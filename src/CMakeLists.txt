
cmake_minimum_required(VERSION 2.8)

project (DistributedBudget)

SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH
   "Single output directory for building all executables.")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )


SET(Poco_DIR ${PROJECT_SOURCE_DIR})

FIND_PACKAGE(Poco REQUIRED)
IF(${Poco_FOUND})
  INCLUDE_DIRECTORIES(${Poco_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Poco_LIBRARY_DIRS})
ENDIF(${Poco_FOUND})


add_subdirectory( ./core )
add_subdirectory( ./unittests )
