#!/bin/sh

if [ -z "$PROJECT_DIR" ]; then
	echo "PROJECT_DIR varible is not specified"
	exit 1;
else
	PROJ_DIR="project_${PROJECT_DIR}"
fi

if [ -z "$PROJECT_GEN" ]; then 
	echo "cmake generator should be defined in PROJECT_GEN variable"
	exit 2
fi

if [ -z "$PROJECT_BUILD_TYPE" ]; then
	echo "PROJECT_BUILD_TYPE not specified, ignore"
else
	OPTIONS="-DCMAKE_BUILD_TYPE=$PROJECT_BUILD_TYPE"
fi

echo "OPTIONS = $OPTIONS"

echo "================================"
echo "project dir = ${PROJ_DIR}"
echo "cmake generator = ${PROJECT_GEN}"
echo "================================"

mkdir -p ${PROJ_DIR}
rm -f ${PROJ_DIR}/CMakeCache.txt

cd ${PROJ_DIR} && cmake ../../src -G "${PROJECT_GEN}" "${OPTIONS}"
