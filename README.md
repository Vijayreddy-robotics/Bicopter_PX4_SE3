# Geometric_SE3_Bicopter

## This repository used basic PX4 flight stack and developed Bicopter UAV Gazebo simulations. The control mixer is modified according to the Bicopter UAV and the attitude and position controllers are replaced by using geometric controller on SE(3). Bicopter CAD model is developed and added .sdf file. The same code can be used for hardware implementation.

### 1. The attitude controller is implemented in RateControl.cpp file and the AttitudeControl.cpp file left ideal.
### 2. The position controller is added in PositionControl.cpp file.
### 3. The Bicopter mixer module is added in ------- using name:
### 4. The Bicopter meshes with the .sdf files were added in ---- using name.

## For further details such as installation, visit the main page 

## Note that the file AttitudeControl.cpp  in src/modules/mc_att_control/AttitudeControl/AttitudeControl.cpp don't have significane since the rate_setpoint is directly calculated from the attitude_setpoint
