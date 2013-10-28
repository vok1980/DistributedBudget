#!/bin/sh

mkdir -p project_eclipse
rm project_eclipse/CMakeCache.txt

cd project_eclipse && cmake ../../src -G "Eclipse CDT4 - Unix Makefiles"
