
cmake_minimum_required(VERSION 2.8)

#   cppUnit

if (UNIX)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
LINK_LIBRARIES(unittests cppunit)
endif(UNIX)


set ( SRC
		main.cpp
	)

add_executable(unittests ${SRC})
