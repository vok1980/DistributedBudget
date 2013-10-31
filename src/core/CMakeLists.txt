
cmake_minimum_required(VERSION 2.8)



set ( INC
		types.h
		ISerializer.h
		IDistributedItem.h
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

add_library(core ${SRC} ${INC})


## Link Poco libraries
find_library(POCO_FOUNDATION PocoFoundation)
find_library(POCO_NET PocoNet)
target_link_libraries(core ${POCO_FOUNDATION} ${POCO_NET})


## Link Thread libraries
find_package(Threads REQUIRED)
target_link_libraries(core ${CMAKE_THREAD_LIBS_INIT})

