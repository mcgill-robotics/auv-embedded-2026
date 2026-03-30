#ifdef DISPLAY_H
//Make sure that the topic names are good check for temp specifically! 

#include "display_main.h"

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include <Wire.h>
#include "MS5837.h"
#include <cmath>

// ROS2 includes
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>
#include <std_msgs/msg/float32.h>
#include <std_msgs/msg/float32_multi_array.h>

void initMainPage();
void handleTouch();
void updateDepthAndTempDisplay();

// Pin Definitions
#define TFT_DC 9
#define TFT_CS 10
#define TOUCH_CS 8
#define TOUCH_IRQ 2

// Display and touchscreen objects
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(TOUCH_CS);

// Depth sensor
MS5837 sensor;


// Colors
#define BATTERY_COLOR ILI9341_RED
#define NUM_COLOR ILI9341_CYAN
#define LABEL_COLOR ILI9341_RED
#define MAIN_RECT_COLOR ILI9341_WHITE
#define DRY_TEST_COLOR ILI9341_GREEN
#define BACKGROUND_COLOR ILI9341_BLACK

#define BLACK     0x0000
#define BLUE      0x001F
#define RED       0xF800
#define GREEN     0x07E0
#define CYAN      0x07FF
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define WHITE     0xFFFF
#define DARK_GRAY  0x2104
#define LIGHT_GRAY 0xC618

// Display dimensions
#define HEIGHT 240
#define WIDTH 320
#define ILI9341_ROTATION_270 1
#define THRUSTER_SPEED 1540
#define MOVING_AVERAGE_SAMPLES 10

// ===== Battery/Tether Variables =====
int tether_new = 0;
int tether_old = -1;
int dual_batt_old = -1;
float batt_voltage_1_new = 0.0;
float batt_voltage_2_new = 0.0;
float voltages_old[] = { -1, -1 };
float voltages_new[] = { -1, -1 };
uint16_t batt_colours[] = { WHITE, WHITE };
float voltage_buffer1[MOVING_AVERAGE_SAMPLES];
int voltage_buffer_index1 = 0;
float voltage_buffer2[MOVING_AVERAGE_SAMPLES];
int voltage_buffer_index2 = 0;

String status_new = "ROS2 Display Ready";
String status_old = "";

// ===== Thruster/Devices Variables =====
uint16_t microseconds[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};
uint16_t dry_test_cmd[8];
uint16_t dry_test_reset[8];
int Sthrusters[8];
int devices_new[] = { 0, 0, 0, 0, 0, 0, 0 };
int thrusters_new[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
float devices_old[] = { -1, -1, -1, -1, -1, -1, -1 };
float thrusters_old[] = { -1, -1, -1, -1, -1, -1, -1, -1 };
bool wasTouched = false;
bool isInDryTestMode = false;
int thruster_states[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// ===== Depth/Temp Variables =====
float current_depth = 0.0;
float current_temperature = 0.0;
float depth_old = -999.0;
float temp_old = -999.0;

// ===== ROS2 Variables =====
// Publishers
rcl_publisher_t sensors_depth_publisher;
std_msgs__msg__Float32 sensors_depth_msg;

rcl_publisher_t sensors_temperature_publisher;
std_msgs__msg__Float32 sensors_temperature_msg;

// Subscribers
rcl_subscription_t propulsion_microseconds_subscriber;
std_msgs__msg__Float32MultiArray propulsion_microseconds_msg;

rcl_subscription_t battery_voltage_subscriber;
std_msgs__msg__Float32MultiArray battery_voltage_msg;

rcl_subscription_t device_status_subscriber;
std_msgs__msg__Float32MultiArray device_status_msg;

// ROS2 Core
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

#define EXECUTE_EVERY_N_MS(MS, X)  do { \
  static volatile int64_t init = -1; \
  if (init == -1) { init = uxr_millis();} \
  if (uxr_millis() - init > MS) { X; init = uxr_millis();} \
} while (0)\

enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

void error_loop() {
    while(1) {
        delay(100);
    }
}

// ===== ROS2 Callbacks =====
void propulsion_microseconds_callback(const void * msgin) {
  const std_msgs__msg__Float32MultiArray * msg = (const std_msgs__msg__Float32MultiArray *)msgin;
  for (int i = 0; i < 8 && i < msg->data.size; i++) {
    microseconds[i] = (uint16_t)msg->data.data[i];
  }
  thrusterStatus(Sthrusters);
}

void battery_voltage_callback(const void * msgin) {
  const std_msgs__msg__Float32MultiArray * msg = (const std_msgs__msg__Float32MultiArray *)msgin;
  if (msg->data.size >= 2) {
    batt_voltage_1_new = msg->data.data[0];
    batt_voltage_2_new = msg->data.data[1];
  }
}

void device_status_callback(const void * msgin) {
  const std_msgs__msg__Float32MultiArray * msg = (const std_msgs__msg__Float32MultiArray *)msgin;
  for (int i = 0; i < 7 && i < msg->data.size; i++) {
    devices_new[i] = (int)msg->data.data[i];
  }
}

// ===== Timer Callback (Publish depth and temp - just publishes already-read values) =====
void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    // Publish the already-read values (read in display_loop)
    sensors_depth_msg.data = current_depth;
    RCSOFTCHECK(rcl_publish(&sensors_depth_publisher, &sensors_depth_msg, NULL));
    
    sensors_temperature_msg.data = current_temperature;
    RCSOFTCHECK(rcl_publish(&sensors_temperature_publisher, &sensors_temperature_msg, NULL));
  }
}

// ===== ROS2 Entity Creation =====
bool create_entities() {
  allocator = rcl_get_default_allocator();

  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  RCCHECK(rclc_node_init_default(&node, "display_node", "", &support));

  // Create publishers
  RCCHECK(rclc_publisher_init_default(
    &sensors_depth_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
    "/sensors/depth/z"));  // Team's topic name - keep as is
  
  RCCHECK(rclc_publisher_init_default(
    &sensors_temperature_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
    "/sensors/temperature"));  // PLACEHOLDER - update with actual team topic name

  // Create subscribers
  RCCHECK(rclc_subscription_init_default(
    &propulsion_microseconds_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32MultiArray),
    "/propulsion/microseconds"));

  RCCHECK(rclc_subscription_init_default(
    &battery_voltage_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32MultiArray),
    "/power/batteries/voltage"));

  RCCHECK(rclc_subscription_init_default(
    &device_status_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32MultiArray),
    "/devices/status"));

  // Create timer (publish every 500ms = 2Hz)
  //CHANGE DEPTH PUB FREQUENCY
  //timer_timeout_ms=1000/Hz
  
  const unsigned int timer_timeout = 67; //67 = 15 Hz, 100 = 10 Hz, 1000 = 1 Hz
  RCCHECK(rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(timer_timeout),
    timer_callback));

  // Create executor
  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 100, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor, &timer));
  RCCHECK(rclc_executor_add_subscription(&executor, &propulsion_microseconds_subscriber, &propulsion_microseconds_msg, &propulsion_microseconds_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &battery_voltage_subscriber, &battery_voltage_msg, &battery_voltage_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &device_status_subscriber, &device_status_msg, &device_status_callback, ON_NEW_DATA));

  return true;
}

void destroy_entities() {
  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&sensors_depth_publisher, &node);
  rcl_publisher_fini(&sensors_temperature_publisher, &node);
  rcl_subscription_fini(&propulsion_microseconds_subscriber, &node);
  rcl_subscription_fini(&battery_voltage_subscriber, &node);
  rcl_subscription_fini(&device_status_subscriber, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}

// ===== Button Structure =====
struct Button {
  int x, y, width, height;
  uint16_t color;
  String label;
};

// Main page buttons
Button buttons[] = {
  {0, 0, 155, 50, BATTERY_COLOR, "0.0V"},
  {160, 0, 155, 50, BATTERY_COLOR, "0.0V"},
  {0, 110, 44, 48, LABEL_COLOR, "IMU"},
  {46, 110, 44, 48, LABEL_COLOR, "P"},
  {92, 110, 44, 48, LABEL_COLOR, "H"},
  {138, 110, 44, 48, LABEL_COLOR, "A"},
  {184, 110, 44, 48, LABEL_COLOR, "FC"},
  {230, 110, 44, 48, LABEL_COLOR, "DC"},
  {276, 110, 44, 48, LABEL_COLOR, "DVL"},
  {0, 164, 320, 30, MAIN_RECT_COLOR, status_new},
  {0, 200, 78, 35, RED, "T"},
  {80, 200, 78, 35, RED, "DB"},
  {160, 200, 78, 35, RED, "Depth"},
  {240, 200, 78, 35, RED, "Temp"},
};

// Thruster buttons for main page
Button buttons_thrusters[] = {
  {0, 55, 38, 50, NUM_COLOR, "1"},
  {40, 55, 38, 50, NUM_COLOR, "2"},
  {80, 55, 38, 50, NUM_COLOR, "3"},
  {120, 55, 38, 50, NUM_COLOR, "4"},
  {160, 55, 38, 50, NUM_COLOR, "5"},
  {200, 55, 38, 50, NUM_COLOR, "6"},
  {240, 55, 38, 50, NUM_COLOR, "7"},
  {280, 55, 38, 50, NUM_COLOR, "8"},
};

// ===== Display Functions =====
void updateDepthAndTempDisplay() {
  // Update DEPTH display (index 12)
  if (abs(current_depth - depth_old) > 0.01) {
    depth_old = current_depth;
    
    char depth_buffer[10];
    dtostrf(current_depth, 5, 2, depth_buffer);
    String depthText = String(depth_buffer) + "m";
    
    tft.fillRoundRect(buttons[12].x, buttons[12].y,
                      buttons[12].width, buttons[12].height, 6, RED);
    
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    int16_t x, y;
    uint16_t w, h;
    tft.getTextBounds(depthText, 0, 0, &x, &y, &w, &h);
    tft.setCursor(buttons[12].x + (buttons[12].width - w) / 2,
                  buttons[12].y + (buttons[12].height - h) / 2);
    tft.print(depthText);
  }
  
  // Update TEMPERATURE display (index 13)
  if (abs(current_temperature - temp_old) > 0.1) {
    temp_old = current_temperature;
    
    char temp_buffer[10];
    dtostrf(current_temperature, 4, 1, temp_buffer);
    String tempText = String(temp_buffer) + "C";
    
    tft.fillRoundRect(buttons[13].x, buttons[13].y,
                      buttons[13].width, buttons[13].height, 6, RED);
    
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    int16_t x, y;
    uint16_t w, h;
    tft.getTextBounds(tempText, 0, 0, &x, &y, &w, &h);
    tft.setCursor(buttons[13].x + (buttons[13].width - w) / 2,
                  buttons[13].y + (buttons[13].height - h) / 2);
    tft.print(tempText);
  }
}

// ===== Battery/Tether Display Functions =====
void tether_dual_battery(float tether_status, float batt1_V, float batt2_V) {
  uint16_t custom_colors[] = { ILI9341_RED, ILI9341_GREEN };

  int temp_tether_status = tether_status;
  float battery_difference = batt2_V - batt1_V;
  bool temp_battery_status = (battery_difference > -0.05 && battery_difference < 0.05) && (batt1_V >= 12.8 && batt2_V >= 12.8);

  if (temp_tether_status != tether_old) {
    uint16_t tether_color = custom_colors[temp_tether_status];
    tft.fillRoundRect(0, 200, 78, 35, 6, tether_color);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setCursor(33, 210);
    tft.print("T");
    tether_old = temp_tether_status;
  }

  if (temp_battery_status != dual_batt_old) {
    uint16_t dual_batt_color = custom_colors[temp_battery_status];
    tft.fillRoundRect(80, 200, 78, 35, 6, dual_batt_color);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(108, 210);
    tft.print("DB");
    dual_batt_old = temp_battery_status;
  }
}

// ===== Moving Average =====
float movingAverage1(float newValue) {
  static float sum = 0;
  sum -= voltage_buffer1[voltage_buffer_index1];
  voltage_buffer1[voltage_buffer_index1] = newValue;
  sum += newValue;
  voltage_buffer_index1 = (voltage_buffer_index1 + 1) % MOVING_AVERAGE_SAMPLES;
  return sum / MOVING_AVERAGE_SAMPLES;
}

float movingAverage2(float newValue) {
  static float sum = 0;
  sum -= voltage_buffer2[voltage_buffer_index2];
  voltage_buffer2[voltage_buffer_index2] = newValue;
  sum += newValue;
  voltage_buffer_index2 = (voltage_buffer_index2 + 1) % MOVING_AVERAGE_SAMPLES;
  return sum / MOVING_AVERAGE_SAMPLES;
}

void batt1(float V1) {
  V1 = round(V1 * 10.0) / 10.0;
  V1 = movingAverage1(V1);
  V1 = round(V1 * 10.0) / 10.0;

  if (voltages_old[0] != V1) {
    voltages_old[0] = V1;

    uint16_t color;
    if (V1 <= 14.8) {
      color = RED;
    } else if (V1 <= 15.8) {
      color = YELLOW;
    } else {
      color = GREEN;
    }

    buttons[0].color = color;
    tft.fillRoundRect(buttons[0].x, buttons[0].y,
      buttons[0].width, buttons[0].height, 8, color);

    char buffer[6];
    dtostrf(V1, 4, 1, buffer);
    String voltageText = String(buffer) + "V";

    tft.setTextColor(BLACK);
    tft.setTextSize(3);

    int16_t x, y;
    uint16_t w, h;
    tft.getTextBounds(voltageText, 0, 0, &x, &y, &w, &h);
    tft.setCursor(buttons[0].x + (buttons[0].width - w) / 2,
                  buttons[0].y + (buttons[0].height - h) / 2);
    tft.print(voltageText);
  }
}

void batt2(float V2) {
  V2 = round(V2 * 10.0) / 10.0;
  V2 = movingAverage2(V2);
  V2 = round(V2 * 10.0) / 10.0;

  voltages_new[1] = V2;
  if (voltages_old[1] != voltages_new[1]) {
    voltages_old[1] = voltages_new[1];

    uint16_t color;
    if (V2 <= 14.8) {
      color = RED;
    } else if (V2 <= 15.8) {
      color = YELLOW;
    } else {
      color = GREEN;
    }

    buttons[1].color = color;
    tft.fillRoundRect(buttons[1].x, buttons[1].y,
      buttons[1].width, buttons[1].height, 8, color);

    char buffer[6];
    dtostrf(V2, 4, 1, buffer);
    String voltageText = String(buffer) + "V";

    tft.setTextColor(BLACK);
    tft.setTextSize(3);

    int16_t x, y;
    uint16_t w, h;
    tft.getTextBounds(voltageText, 0, 0, &x, &y, &w, &h);
    tft.setCursor(buttons[1].x + (buttons[1].width - w) / 2,
                  buttons[1].y + (buttons[1].height - h) / 2);
    tft.print(voltageText);
  }
}

// ===== Status Bar Update Function =====
void updateStatusDisplay(String newStatus) {
  if (newStatus != status_old) {
    tft.fillRoundRect(0, 164, 320, 30, 8, MAIN_RECT_COLOR);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);

    int16_t x, y;
    uint16_t w, h;
    tft.getTextBounds(newStatus, 0, 0, &x, &y, &w, &h);
    tft.setCursor((320 - w) / 2, 164 + (30 - h) / 2);
    tft.print(newStatus);

    status_old = newStatus;
  }
}

// ===== Thruster Functions =====
void thrusterStatus(int Sthrusters[]) {
  for (int i = 0; i < 8; i++) {
    if (microseconds[i] == 1500) {
      Sthrusters[i] = 0;
    } else {
      Sthrusters[i] = 1;
    }
  }
}

void thrusters(int T1, int T2, int T3, int T4, int T5, int T6, int T7, int T8) {
  if (isInDryTestMode) return;

  int temp_thrusters[] = { T1, T2, T3, T4, T5, T6, T7, T8 };
  uint16_t thruster_colors[] = {WHITE, CYAN};

  for (int i = 0; i < 8; i++) {
    uint16_t color = thruster_colors[temp_thrusters[i]];
    if (temp_thrusters[i] != thrusters_old[i]) {
      buttons_thrusters[i].color = color;
    }
  }

  for (const Button &btn : buttons_thrusters) {
    tft.fillRoundRect(btn.x, btn.y, btn.width, btn.height, 8, btn.color);
    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(btn.x + 5, btn.y + 10);
    tft.setTextSize(2);
    tft.print(btn.label);
  }

  for (int i = 0; i < 8; i++) {
    thrusters_old[i] = temp_thrusters[i];
  }
}

// ===== Device Functions =====
void device(int IMU, int DVL, int PS, int HYD, int ACT, int FC, int DC) {
  int temp_devices[] = {IMU, DVL, PS, HYD, ACT, FC, DC};
  uint16_t device_colors[] = {RED, GREEN};
  int device_x[] = {0, 276, 46, 92, 138, 184, 230};
  int device_y = 110;
  int device_width = 44;
  int device_height = 48;

  for (int i = 0; i < 7; i++) {
    if (temp_devices[i] != devices_old[i]) {
      uint16_t color = device_colors[temp_devices[i]];
      tft.fillRoundRect(device_x[i], device_y, device_width, device_height, 8, color);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      switch (i) {
        case 0: tft.setCursor(device_x[i] + 4,  device_y + 15); tft.print("IMU"); break;
        case 1: tft.setCursor(device_x[i] + 6,  device_y + 15); tft.print("DVL"); break;
        case 2: tft.setCursor(device_x[i] + 17, device_y + 15); tft.print("P");   break;
        case 3: tft.setCursor(device_x[i] + 17, device_y + 15); tft.print("H");   break;
        case 4: tft.setCursor(device_x[i] + 17, device_y + 15); tft.print("A");   break;
        case 5: tft.setCursor(device_x[i] + 12, device_y + 15); tft.print("FC");  break;
        case 6: tft.setCursor(device_x[i] + 12, device_y + 15); tft.print("DC");  break;
      }
      devices_old[i] = temp_devices[i];
    }
  }
}

// ===== Dry Test Functions =====
void initializeThrusterMessages() {
  for (int i = 0; i < 8; i++) {
    dry_test_cmd[i]   = 1500;
    dry_test_reset[i] = 1500;
  }
}

void optimized_dry_test(int t) {
  Serial.print("[DRY TEST] Firing thruster ");
  Serial.println(t + 1);
  delay(1000);
  Serial.println("[DRY TEST] Done");
}

void updateThrusters_page2() {
  uint16_t thruster_colors[] = {DARK_GRAY, CYAN};

  for (int i = 0; i < 8; i++) {
    int row = i / 4;
    int col = i % 4;
    int x = 43 + col * 60;
    int y = 65 + row * 60;
    uint16_t color = thruster_colors[thruster_states[i]];

    tft.fillRoundRect(x + 2, y + 2, 46, 46, 10, color);
    tft.setCursor(x + 15, y + 12);
    tft.setTextColor(DARK_GRAY);
    tft.setTextSize(2);
    tft.print(i + 1);
  }
}

void initDryTestPage() {
  tft.setRotation(1);
  tft.fillScreen(BACKGROUND_COLOR);

  for (int i = 0; i < 8; i++) {
    int row = i / 4;
    int col = i % 4;
    int x = 43 + col * 60;
    int y = 65 + row * 60;
    tft.drawRoundRect(x, y, 50, 50, 10, LIGHT_GRAY);
  }

  tft.setCursor(WIDTH / 2 - 110, HEIGHT / 3 - 30);
  tft.setTextColor(LIGHT_GRAY);
  tft.setTextSize(1);
  tft.println("-------------Dry Test Mode-------------");

  int backButtonX = 8;
  int backButtonY = 10;
  int backButtonWidth = 60;
  int backButtonHeight = 30;
  tft.fillRoundRect(backButtonX, backButtonY, backButtonWidth, backButtonHeight, 5, LIGHT_GRAY);
  tft.drawRoundRect(backButtonX, backButtonY, backButtonWidth, backButtonHeight, 5, WHITE);
  tft.setCursor(backButtonX + 10, backButtonY + 8);
  tft.setTextColor(DARK_GRAY);
  tft.setTextSize(2);
  tft.print("BACK");
}

// ===== Main Page Init =====
void initMainPage() {
  tft.setRotation(1);
  tft.fillScreen(BACKGROUND_COLOR);

  for (int i = 0; i < 14; i++) {
    const Button &btn = buttons[i];
    tft.fillRoundRect(btn.x, btn.y, btn.width, btn.height, 8, btn.color);
    
    if (btn.label == "ROS2 Display Ready" || btn.label == "Depth" || btn.label == "Temp") {
      tft.setTextColor(BLACK);
    } else {
      tft.setTextColor(WHITE);
    }
    
    int16_t x, y;
    uint16_t w, h;
    tft.getTextBounds(btn.label, 0, 0, &x, &y, &w, &h);
    
    if (btn.label != "0.0V") {
      tft.setTextSize(2);
      if (btn.label == "IMU") {
        tft.setCursor(btn.x + (btn.width - w) / 2 - 9, btn.y + (btn.height - h) / 2 - 5);
      } else {
        tft.setCursor(btn.x + (btn.width - w) / 2, btn.y + (btn.height - h) / 2);
      }
      tft.print(btn.label);
    }
  }

  updateStatusDisplay(status_new);

  voltages_old[0] = -1;
  voltages_old[1] = -1;
  batt1(batt_voltage_1_new);
  batt2(batt_voltage_2_new);
}

// ===== Touch Handler =====
void handleTouch() {
  if (ts.touched()) {
    if (!wasTouched) {
      wasTouched = true;
      TS_Point p = ts.getPoint();
      p.x = map(p.x, 300, 4000, 320, 0);
      p.y = map(p.y, 200, 4000, 240, 0);
      int16_t x = p.x;
      int16_t y = p.y;

      if (!isInDryTestMode) {
        if (x >= 0 && x <= 78 && y >= 200 && y <= 235) {
          tether_dual_battery(tether_new, batt_voltage_1_new, batt_voltage_2_new);
        }
        else if (x >= 80 && x <= 158 && y >= 200 && y <= 235) {
          tether_dual_battery(tether_new, batt_voltage_1_new, batt_voltage_2_new);
        }
        else if (x >= 0 && x <= 300 && y >= 60 && y <= 110) {
          isInDryTestMode = true;
          initDryTestPage();
        }
      } else {
        if (x >= 8 && x <= 68 && y >= 10 && y <= 40) {
          isInDryTestMode = false;
          initMainPage();
          batt_voltage_1_new = 0.0;
          batt_voltage_2_new = 0.0;
          batt1(batt_voltage_1_new);
          batt2(batt_voltage_2_new);
          tether_dual_battery(tether_new, batt_voltage_1_new, batt_voltage_2_new);
        } else {
          for (int i = 0; i < 8; i++) {
            int row = i / 4;
            int col = i % 4;
            int x_start = 43 + col * 60;
            int y_start = 65 + row * 60;

            if (x >= x_start && x <= x_start + 50 && y >= y_start && y <= y_start + 50) {
              thruster_states[i] = !thruster_states[i];
              updateThrusters_page2();
              optimized_dry_test(i);
              thruster_states[i] = 0;
              updateThrusters_page2();
              break;
            }
          }
        }
      }
    }
  } else {
    wasTouched = false;
  }
}

// ===== Setup =====
void display_setup() {
  Serial.begin(115200);
  
  // Initialize depth sensor
  Wire.begin();
  if (!sensor.init()) {
    Serial.println("[WARN] Depth sensor init failed - continuing anyway");
    status_new = "Depth Sensor Error";
  } else {
    Serial.println("[INFO] Depth sensor initialized");
    sensor.setModel(MS5837::MS5837_30BA);
    sensor.setFluidDensity(997);
  }

  // Initialize display
  tft.begin();
  ts.begin();
  ts.setRotation(1);

  // Initialize thruster command arrays
  initializeThrusterMessages();

  // Initialize moving average buffers
  for (int i = 0; i < MOVING_AVERAGE_SAMPLES; i++) {
    voltage_buffer1[i] = 0;
    voltage_buffer2[i] = 0;
  }

  // Initialize ROS2 messages
  propulsion_microseconds_msg.data.size = 8;
  propulsion_microseconds_msg.data.capacity = 8;
  propulsion_microseconds_msg.data.data = (float*)malloc(propulsion_microseconds_msg.data.capacity * sizeof(float));
  
  battery_voltage_msg.data.size = 2;
  battery_voltage_msg.data.capacity = 2;
  battery_voltage_msg.data.data = (float*)malloc(battery_voltage_msg.data.capacity * sizeof(float));
  
  device_status_msg.data.size = 7;
  device_status_msg.data.capacity = 7;
  device_status_msg.data.data = (float*)malloc(device_status_msg.data.capacity * sizeof(float));
  
  sensors_depth_msg.data = 0.0;
  sensors_temperature_msg.data = 0.0;

  // Initialize micro-ROS
  set_microros_transports();
  
  // Start with initial display
  initMainPage();
  
  // Initial state
  state = WAITING_AGENT;
}

// ===== Loop =====
void display_loop() {
  // Handle touch input
  handleTouch();
  
  // Read depth sensor (read() returns void, just call it)
  sensor.read();
  current_depth = sensor.depth();
  current_temperature = sensor.temperature();
  updateDepthAndTempDisplay();
  
  // Update other display elements
  batt1(batt_voltage_1_new);
  batt2(batt_voltage_2_new);
  tether_dual_battery(tether_new, batt_voltage_1_new, batt_voltage_2_new);
  device(devices_new[0], devices_new[1], devices_new[2], devices_new[3],
         devices_new[4], devices_new[5], devices_new[6]);
  thrusters(Sthrusters[0], Sthrusters[1], Sthrusters[2], Sthrusters[3],
            Sthrusters[4], Sthrusters[5], Sthrusters[6], Sthrusters[7]);
  
  // ROS2 state machine
  switch (state) {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
      break;
    case AGENT_AVAILABLE:
      state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) {
        destroy_entities();
      }
      break;
    case AGENT_CONNECTED:
      EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
      if (state == AGENT_CONNECTED) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
      }
      break;
    case AGENT_DISCONNECTED:
      destroy_entities();
      state = WAITING_AGENT;
      break;
    default:
      break;
  }
  
  delay(10);
}

#endif