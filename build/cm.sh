#!/bin/sh

if [ -z $1 ]; then
	echo "project dir should be the first argument"
	exit 1;
else
	PROJ_DIR="project_$1"
fi

if [ -z "$2" ]; then
	echo "cmake generator should be the second argument"
	exit 2;
else
	GENERATOR=$2
fi

echo "================================"
echo "project dir = ${PROJ_DIR}"
echo "cmake generator = ${GENERATOR}"
echo "================================"

mkdir -p ${PROJ_DIR}
rm -f ${PROJ_DIR}/CMakeCache.txt

cd ${PROJ_DIR} && cmake ../../src -G "${GENERATOR}"
