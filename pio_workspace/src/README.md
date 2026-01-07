# Source Code Overview

This directory contains the embedded source code for the McGill Robotics AUV systems. The code here is responsible for interfacing with onboard hardware, running micro ROS nodes, and publishing sensor data to the ROS 2 network.

---

## Display Board

The Display Board firmware is implemented in `display_main.cpp`. In addition to handling the TFT display and touchscreen, this board interfaces with a pressure sensor and publishes depth data over micro ROS.

---

## ROS 2 Topics

The following ROS 2 topics are published by the Display Board (`display_main.cpp`).

### Depth Sensor Publisher
- **Node:** `display_node`
- **Source File:** `display_main.cpp`
- **Topic:** `/sensors/depth/z`
- **Message Type:** `std_msgs/msg/Float64`
- **Units:** meters
- **Sensor:** MS5837 (30BA)

The depth value is read from the MS5837 pressure sensor and published at 1 Hz using micro ROS.
