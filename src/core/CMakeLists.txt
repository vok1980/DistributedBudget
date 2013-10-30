
cmake_minimum_required(VERSION 2.8)



set ( INC
		types.h
		ISerializer.h
		IDistributedItem.h
		Transaction.h
        Account.h
        Budget.h
	)

set ( SRC
		Transaction.cpp
        Account.cpp
        Budget.cpp
	)

add_library(core ${SRC} ${INC})
