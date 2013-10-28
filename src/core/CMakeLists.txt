
cmake_minimum_required(VERSION 2.8)

set ( INC
		IDistributedItem.h
		Transaction.h
	)

set ( SRC
		Transaction.cpp
	)

add_library(core ${SRC} ${INC})
