#!/usr/bin/env bash

export PX4_GZ_MODELS=/home/vijay/PX4-Autopilot/Tools/simulation/gz/models
export PX4_GZ_WORLDS=/home/vijay/PX4-Autopilot/Tools/simulation/gz/worlds

export GZ_SIM_RESOURCE_PATH=$GZ_SIM_RESOURCE_PATH:$PX4_GZ_MODELS:$PX4_GZ_WORLDS
