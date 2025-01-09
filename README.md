# Geometric_SE3_Bicopter

#### This repository used the PX4 flight stack and developed Bicopter UAV Gazebo simulations. The control mixer is modified according to the Bicopter UAV, and the attitude and position controllers are replaced by a geometric controller on SE(3). The same code can be used for hardware implementation.


## Code changes

### --> A new airframe for Bicopter is added in PX4-Autopilot/ROMFS/px4fmu_common/init.d-posix/airframes:

### -->  The Bicopter meshes and the model.sdf files are added in PX4-Autopilot/Tools/simulation/gz/models/bicopter.

### --> Attitude control on SO(3) is implemented in rate_ontrol.cpp file in the module src/lib/rate_control and  src/modules/mc_rate_control/MulticopterRateControl.cpp 

### --> Position control on SE(3) is implemented in PositionControl.cpp in module src/modules/mc_pos_control

### Note that the file AttitudeControl.cpp  in src/modules/mc_att_control/AttitudeControl/AttitudeControl.cpp is insignificant since the rate_setpoint is directly calculated from the attitude_setpoint in rate_control.cpp

#### For further details such as installation, visit the main page 
