# McGill Robotics AUV Embedded 2026

Welcome to the AUV Embedded 2026 repository. This repository is created and maintained by the 2026 McGill Robotics AUV Electrical team. It serves as a platform for sharing, calibrating, and version controlling the embedded software developed for our Autonomous Underwater Vehicle (AUV).

## About Us

We are a dedicated team of students from McGill Robotics, focused on designing and implementing the PCBs and embedded systems that power our underwater robot. Our mission is to enable autonomous navigation and task performance through robust electrical engineering and embedded software development.

## What You Will Find Here

- **Embedded Software**: Source code and libraries for the AUV embedded subsystems
- **Team Structure**: Information about team members and roles
- **Tutorials**: Guides on using ROS 2, micro ROS, and Arduino within the AUV stack

For more detail, please visit our [Wiki](https://github.com/mcgill-robotics/auv-embedded-2025/wiki).

---

## ROS 2 Topics

The following ROS 2 topics are **published by the Display Board**, implemented in `display_main.cpp`.

### Depth Sensor Publisher
- **Node:** `display_node`
- **Source File:** `display_main.cpp`
- **Topic:** `/sensors/depth/z`
- **Message Type:** `std_msgs/msg/Float64`
- **Units:** meters
- **Sensor:** MS5837 (30BA)

The depth value is read from the MS5837 pressure sensor and published at 1 Hz using micro ROS.
