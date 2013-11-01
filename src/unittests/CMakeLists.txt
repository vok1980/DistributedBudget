
cmake_minimum_required(VERSION 2.8)

#   cppUnit

if (UNIX)
#cppunit-config --prefix
EXEC_PROGRAM(cppunit-config ARGS --prefix RETURN_VALUE _return_VALUE OUTPUT_VARIABLE CPPUNIT_PREFIX)
include_directories(${CPPUNIT_PREFIX}/include)
link_directories(${CPPUNIT_PREFIX}/lib)
LINK_LIBRARIES(unittests cppunit)
endif(UNIX)


set ( SRC
		main.cpp
        SimpleTest.cpp
	)

set ( INCL
        SimpleTest.h
	)


add_executable(unittests ${SRC} ${INCL})

