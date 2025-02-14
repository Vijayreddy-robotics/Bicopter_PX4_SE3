# Geometric_SE3_Bicopter

#### This repository used the PX4 flight stack and developed Bicopter UAV Gazebo simulations. The control mixer is modified according to the Bicopter UAV, and the attitude and position controllers are replaced by a geometric controller on SE(3). The same code can be used for hardware implementation.

Software Version: v1.15.0

Tested with the hardware: Pixhawk v2.4.8

Host computer: Windows 11 pro installed with the WSL Ubuntu 22.04.3 LTS 

Gazebo: Gazebo Sim v8.6.0

## Code changes

 --> A new airframe for Bicopter is added in `PX4-Autopilot/ROMFS/px4fmu_common/init.d-posix/airframes/2101_gz_bicopter`:

 -->  The Bicopter `meshes` and the `model.sdf` files are added in `PX4-Autopilot/Tools/simulation/gz/models/bicopter`.

 --> Attitude control on SO(3) is implemented in the `rate_ontrol.cpp` file in the module `src/lib/rate_control` and `src/modules/mc_rate_control/MulticopterRateControl.cpp` 

 --> Position control on SE(3) is implemented in `PositionControl.cpp` in module `src/modules/mc_pos_control`

 Note that the file `AttitudeControl.cpp`  in `src/modules/mc_att_control/AttitudeControl/AttitudeControl.cpp` is insignificant since the `rate_setpoint` is directly calculated from the `attitude_setpoint` in `rate_control.cpp`

#### For further details such as installation, visit the main px4 document page: https://docs.px4.io/main/ 

## Instructions

--> After installation, to run the Bicopter in SITL Gazebo, use 
```bash
    /PX4-Autopilot$ make px4_sitl gz_bicopter
```
