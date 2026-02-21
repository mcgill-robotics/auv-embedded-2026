#ifdef DISPLAY_H

#include "display_main.h"

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"
#include <Wire.h>
#include "MS5837.h"

// COPIED THIS FROM POWER BOARD CODE 
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>
#include <std_msgs/msg/float64.h>

// Display pins definition
#define TFT_DC 9
#define TFT_CS 10
#define TOUCH_CS 8
#define TOUCH_IRQ 2

// Displauy and touchscreen objects
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(TOUCH_CS);
MS5837 sensor;

// Power board led pin (not sure if needed)

// Depth publishers (instead of power publishers)
rcl_publisher_t sensors_depth_publisher;
std_msgs__msg__Float64 sensors_depth_msg;

// COPIED EXACTLY FROM POWER BOARD 
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}
#define EXECUTE_EVERY_N_MS(MS, X) do { \
  static volatile int64_t init = -1; \
  if (init == -1) { init = uxr_millis();} \
  if (uxr_millis() - init > MS) { X; init = uxr_millis();} \
} while (0)


enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE, 
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;


void error_loop() {
    int error = 0;
    while (error < 10) {
        delay(100);
        error++;
    }
}

// COPIED FROM POWER BOARD STOP 
//float count = 0;

//DEPTH TIMER CALLBACK
void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    sensor.read();
    sensors_depth_msg.data = sensor.depth();
    //sensors_depth_msg.data = count++;
    RCSOFTCHECK(rcl_publish(&sensors_depth_publisher, &sensors_depth_msg, NULL));
    
    // Debug print in case you need it if it bugs or smt
    //serial.print("Published depth: ");
    //serial.println(sensors_depth_msg.data);
  }
}

//ADAPTED CREATE_ENTITIES MORE COPY PASTING FROM POWER BOARD
bool create_entities() {
  allocator = rcl_get_default_allocator();

  // COPIED PATTERN FROM POWER BOARD
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  RCCHECK(rclc_node_init_default(&node, "display_node", "", &support));

  // DISPLAY DEPTH PUBLISHER
  RCCHECK(rclc_publisher_init_default(
    &sensors_depth_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float64), "/sensors/depth/z"));

  // COPIED PATTERN FROM POWER BOARD
  const unsigned int timer_timeout = 1000; // this is where you can change the Hz (1000 = 1Hz) 
  //timer_timeout_ms = 1000 / Hz
  RCCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(timer_timeout), timer_callback));

  // COPIED EXECUTOR PATTERN FROM POWER BOARD
  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor, &timer));

  return true;
}

// COPIED DESTROY_ENTITIES FROM POWER BOARD
void destroy_entities() {
  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&sensors_depth_publisher, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}

// SIMPLIFIED DISPLAY FUNCTIONS
void updateDisplay() {
  // Simple display update to show depth and connection status
  static unsigned long lastDisplayUpdate = 0;
  if (millis() - lastDisplayUpdate > 500) { // Update every 500ms
    lastDisplayUpdate = millis();
    
    // Clear area and show depth
    tft.fillRect(50, 50, 200, 60, ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setCursor(50, 50);
    tft.print("Depth: ");
    tft.print(sensor.depth());
    tft.print(" m");
    
    // Show connection status
    tft.setCursor(50, 80);
    tft.print("ROS2: ");
    switch(state) {
      case WAITING_AGENT: tft.print("Waiting"); break;
      case AGENT_AVAILABLE: tft.print("Available"); break;
      case AGENT_CONNECTED: tft.print("Connected"); break;
      case AGENT_DISCONNECTED: tft.print("Disconnected"); break;
    }
  }
}

void handleTouch() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    tft.fillCircle(p.x, p.y, 5, ILI9341_RED);
    delay(100);
    tft.fillCircle(p.x, p.y, 5, ILI9341_BLACK);
  }
}

void initDisplay() {
  tft.begin();
  ts.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(80, 10);
  tft.print("Depth Sensor ROS2");
  
  //serial.println("Display initialized");
}

void display_setup() {
  // Initializing serial for debugging
  Serial.begin(115200);
  delay(2000);
  //serial.println("Depth Sensor ROS2 Starting");

  // Initializing display
  initDisplay();

  // Loops until depth sensor initializes (BLOCKING LOOP)
  Wire.begin();
  while (!sensor.init()) {
    //serial.println("Depth sensor init failed");
    //return;
  }
  delay(1000);
  sensor.setModel(MS5837::MS5837_30BA);
  sensor.setFluidDensity(997);
  //serial.println("Depth sensor initialized");
  
  // COPIED MICRO-ROS INIT FROM POWER BOARD
  
  set_microros_transports();
  delay(2000);
  
  // Initializing  message
  sensors_depth_msg.data = 0.0;
  
  // COPIED INITIAL STATE FROM POWER BOARD
  state = WAITING_AGENT;
  // ADDING SOME PRINT STATEMENTS FOR DEBUGGING
  //serial.println("Setup complete - waiting for ROS2 agent");
}

void display_loop() {
  handleTouch();           
  updateDisplay();       

  // COPIED THE CASE BLACK STATE MACHINE FROM POWER BOARD
  switch (state) {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
      break;
    case AGENT_AVAILABLE:
      state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) {
        destroy_entities();
      };
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