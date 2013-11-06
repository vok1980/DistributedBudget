
cmake_minimum_required(VERSION 2.8)



set ( INC
		types.h
		ISerializer.h
		IDistributedItem.h
        IBalanceStriker.h
		Transaction.h
        Account.h
        Budget.h
        Category.h
	)

set ( SRC
		Transaction.cpp
        Account.cpp
        Budget.cpp
        Category.cpp
	)


## Find Thread libraries
find_package(Threads REQUIRED)


add_library(core ${SRC} ${INC})
target_link_libraries(core ${CMAKE_THREAD_LIBS_INIT} )


