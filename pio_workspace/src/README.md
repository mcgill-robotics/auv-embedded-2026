_As of September 2025, our team has fully migrated from ROSSerial (ROS 1) to micro-ROS (ROS 2). All new code contributions must use the micro-ROS library. Support for rosserial has been deprecated and will not be merged into the main branch. Please note that files containing "ros1" in their names are not deployed._

# Source Code Overview

This directory contains the embedded source code for the McGill Robotics AUV systems with the exception of the Hydrophone board. The code is responsible for interfacing with onboard hardware, running micro ROS nodes, and publishing sensor data to the ROS 2 network.

## Display Board

The Display Board firmware is implemented in `display_main.cpp`. In addition to handling the TFT display and touchscreen, this board interfaces with a pressure sensor and publishes depth data over micro ROS.

### ROS 2 Topics

The following ROS 2 topics are published by the Display Board (`display_main.cpp`).

#### Depth Sensor Publisher
- **Node:** `display_node`
- **Source File:** `display_main.cpp`
- **Topic:** `/sensors/depth/z`
- **Message Type:** `std_msgs/msg/Float64`
- **Units:** meters
- **Sensor:** MS5837 (30BA)

The depth value is read from the MS5837 pressure sensor and published periodically using a micro ROS timer.

### Publishing Rate (Hz)

The publishing frequency of the depth sensor is controlled by the micro ROS timer defined in `display_main.cpp`:

```cpp
// COPIED PATTERN FROM POWER BOARD
const unsigned int timer_timeout = 1000; // timer period in milliseconds
```

This value represents the **timer period in milliseconds**, not the frequency directly.

#### Frequency Formula

```text
timer_timeout_ms = 1000 / frequency_in_hz
```

#### Examples

```text
1 Hz  → timer_timeout = 1000
10 Hz → timer_timeout = 100
15 Hz → timer_timeout = 67
20 Hz → timer_timeout = 50
```

For example, to publish depth data at approximately **15 Hz**, use:

```cpp
const unsigned int timer_timeout = 67; // ~15 Hz
```

Because the timer period must be an integer number of milliseconds, some frequencies are approximated.

### Notes
- The microROS executor must run at least as fast as the timer period to ensure callbacks are serviced on time.
- Increasing the publish rate increases CPU load and I2C traffic; ensure the sensor and microcontroller can support the selected frequency.

## Actuator Board

### Hardware Connections

Based on the pin mapping in the code, connect your servos to the following ports on the board:

* **Torpedo Servo:** Connect to port **J1** (Teensy Pin 8)
* **Grabber Servo:** Connect to port **J3** (Teensy Pin 10)

---

### ROS 2 Commands

The board runs a micro-ROS node named `actuator_node` and listens to two topics. Both topics expect messages of type `std_msgs/msg/UInt8`.

Publish the corresponding integer value to trigger the desired state:

| Actuator | ROS 2 Topic | Value (`data`) | Action |
| :--- | :--- | :--- | :--- |
| **Torpedo** | `/actuators/torpedo` | `0` | Closed |
| **Torpedo** | `/actuators/torpedo` | `1` | Shoot One |
| **Torpedo** | `/actuators/torpedo` | `2` | Shoot Both |
| **Grabber** | `/actuators/grabber` | `0` | Open |
| **Grabber** | `/actuators/grabber` | `1` | Closed |

### Example CLI Commands

To test the actuators from your terminal, you can publish messages directly using the following commands:

**Open the grabber:**
