
cmake_minimum_required(VERSION 2.8)


project (DistributedBudget)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )


add_subdirectory( ./core )
add_subdirectory( ./unittests )
