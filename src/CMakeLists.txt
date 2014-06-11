
cmake_minimum_required(VERSION 2.8)

project (DistributedBudget)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH
   "Single output directory for building all executables.")

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
endif(UNIX)

add_definitions(-DPOCO_STATIC)

set(CMAKE_MODULE_PATH 	${CMAKE_MODULE_PATH} 
						"${CMAKE_SOURCE_DIR}/cmake/Modules/")

FIND_PACKAGE(Poco REQUIRED)
INCLUDE_DIRECTORIES(${Poco_INCLUDE_DIRS})
LINK_DIRECTORIES(${Poco_LIBRARY_DIRS})

find_package(Protobuf REQUIRED)

add_subdirectory( ./core )
add_subdirectory( ./unittests )
add_subdirectory( ./platform )

ENABLE_TESTING()
add_test(NAME unittests COMMAND unittests)

