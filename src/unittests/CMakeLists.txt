
cmake_minimum_required(VERSION 2.8)


FIND_PACKAGE(CppUnit REQUIRED)
include_directories(${CppUnit_INCLUDE})

if (NOT CppUnit_LIB_DEBUG)
  set(CppUnit_LIB_DEBUG ${CppUnit_LIB})
endif (NOT CppUnit_LIB_DEBUG)

set(unittests_libs    core
                      "optimized" ${CppUnit_LIB}
                      "debug"     ${CppUnit_LIB_DEBUG}
    )

if (NOT WIN32)
  set(unittests_libs  ${unittests_libs}
                      "optimized" PocoFoundation
                      "debug"     PocoFoundationd
                      )
endif (NOT WIN32)


set ( SRC
        main.cpp
        SimpleTest.cpp
        AccountBalanceTest.cpp
        TransactionIdTest.cpp
        BudgetBalanceTest.cpp
        MemSerializerTest.cpp
	)

set ( INCL
        SimpleTest.h
        AccountBalanceTest.h
        TransactionIdTest.h
        BudgetBalanceTest.h
        MemSerializerTest.h
	)

include_directories(.)
include_directories(./../core)

add_executable(unittests ${SRC} ${INCL})

target_link_libraries(unittests ${unittests_libs})

