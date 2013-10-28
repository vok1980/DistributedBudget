#!/bin/sh

mkdir -p project_xcode
cd project_xcode && cmake ../../src -G Xcode
