
cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(CppUnit REQUIRED)
include_directories(${CppUnit_INCLUDE})
link_directories(${CppUnit_LIBRARY_DIR})

set ( SRC
		main.cpp
        SimpleTest.cpp
        AccountBalanceTest.cpp
        TransactionIdTest.cpp
        BudgetBalanceTest.cpp
	)

set ( INCL
        SimpleTest.h
        AccountBalanceTest.h
        TransactionIdTest.h
        BudgetBalanceTest.h
	)


add_executable(unittests ${SRC} ${INCL})

target_link_libraries(unittests
                                "optimized" PocoFoundation
                                "debug" PocoFoundationd
                                            core
                                "optimized" ${CppUnit_LIB}
                                "debug"     ${CppUnit_LIB_DEBUG}
                      )

