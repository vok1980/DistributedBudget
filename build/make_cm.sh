#!/bin/sh

export PROJECT_BUILD_TYPE=Release
export PROJECT_DIR="make"
export PROJECT_GEN="Unix Makefiles"

./cm.sh && cd project_make && make
