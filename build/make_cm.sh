#!/bin/sh

mkdir -p project_make
cd project_make && cmake -DSEQAN_C++11_STANDARD=ON ../../src 
