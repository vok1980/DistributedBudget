
cmake_minimum_required(VERSION 2.8)




set ( INC
		types.h
		IDistributedItem.h
		Transaction.h
        Account.h
	)

set ( SRC
		Transaction.cpp
        Account.cpp
	)

add_library(core ${SRC} ${INC})
