
cmake_minimum_required(VERSION 2.8)


#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set ( INC
		IDistributedItem.h
		Transaction.h
        Account.h
	)

set ( SRC
		Transaction.cpp
        Account.cpp
	)

add_library(core ${SRC} ${INC})
