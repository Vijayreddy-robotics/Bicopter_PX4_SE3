# Geometric_SE3_Bicopter

## This repository used basic PX4 flight stack and developed Bicopter UAV Gazebo simulations. The control mixer is modified according to the Bicopter UAV and the attitude and position controllers are replaced by using geometric controller on SE(3). Bicopter CAD model is developed and added .sdf file. The same code can be used for hardware implementation.


## For further details such as installation, visit the main page 

## --> The Bicopter mixer module is added in ------- using name:

## -->  The Bicopter meshes with the .sdf files were added in ---- using name.

## --> Attitude control on SO(3) is implemented in rate_ontrol.cpp file in the module src/lib/rate_control and  src/modules/mc_rate_control/MulticopterRateControl.cpp 

## --> Position control on SE(3) is implemented in PositionControl.cpp in module src/modules/mc_pos_control

## Note that the file AttitudeControl.cpp  in src/modules/mc_att_control/AttitudeControl/AttitudeControl.cpp don't have significance since the rate_setpoint is directly calculated from the attitude_setpoint in rate_control.cpp
