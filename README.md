# McGill Robotics AUV Embedded 2026

Welcome to the AUV Embedded 2026 repository! This repository is created and maintained by the 2026 McGill Robotics AUV Electrical team. It serves as a platform for sharing, calibrating, and version-controlling the embedded software we develop for our Autonomous Underwater Vehicle (AUV).

## About Us

We are a dedicated team of students from McGill Robotics, focused on designing and implementing the PCBs and embedded systems that power our underwater robot. Our mission is to enable autonomous navigation and task performance through advanced electrical engineering and software development.

## What You'll Find Here

- **Embedded Software**: Source code and libraries for our AUV's embedded systems.
- **Team Structure**: Information about our team members and roles.
- **Tutorials**: Guides and tutorials on using ROS (Robot Operating System) and Arduino for our projects.

For more detail please visit our [Wiki](https://github.com/mcgill-robotics/auv-embedded-2026/wiki).

## Hydrophone related work 

You will find in the `dev/hydrophone` branch the following folders : 
- `documentation`, documenting the design of the new hydrophone ADC board. The documentation was written using _mkdocs_, and to view it you'll need to 1. clone the repository locally, then install mkdocs using `pip install mkdocs` and finally render the web documentation using `mkdocs serve` _in the `documentation` folder_
- `kicad`, which contains the source files (`ADC.kicad_pro`) for the design of the new ADC board
- `ltspice`, for the LTSPICE simulations of the ADC board signal chain.

If you have any questions regarding the hydrophone board design please contact @Oscar-T24
