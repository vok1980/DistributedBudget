
SET(CPPUNIT_DIR_SEARCH $ENV{CPPUNIT_ROOT})

IF(CPPUNIT_DIR_SEARCH)
  FILE(TO_CMAKE_PATH ${CPPUNIT_DIR_SEARCH} CPPUNIT_DIR_SEARCH)
ENDIF(CPPUNIT_DIR_SEARCH)

if (WIN32)
    set ( CPPUNIT_DIR_SEARCH
                ${CPPUNIT_DIR_SEARCH}
                c:
                d:
                e:
    )
endif(WIN32)


SET(SUFFIX_FOR_PATH
    cppunit
    cppunit-1.12.1
)

FIND_PATH( CPPUNIT_ROOT_DIR NAMES include/cppunit/Test.h PATH_SUFFIXES ${SUFFIX_FOR_PATH} PATHS ${CPPUNIT_DIR_SEARCH} )

if ( CPPUNIT_ROOT_DIR )

    if ( EXISTS ${CPPUNIT_ROOT_DIR}/include )
        set(CppUnit_INCLUDE ${CPPUNIT_ROOT_DIR}/include )
    endif()

    if ( EXISTS ${CPPUNIT_ROOT_DIR}/lib )
        set(CppUnit_LIBRARY ${CPPUNIT_ROOT_DIR}/lib )
    endif()

    set( CppUnit_FOUND TRUE )

else( CPPUNIT_ROOT_DIR )
    
    if (UNIX)

        #cppunit-config --prefix
        EXEC_PROGRAM(cppunit-config ARGS --prefix RETURN_VALUE _return_VALUE OUTPUT_VARIABLE CPPUNIT_PREFIX)

        message(STATUS "cppunit-config return prefix \"${CPPUNIT_PREFIX}\"")

        if ( ${CPPUNIT_PREFIX} STREQUAL "" )
            message(WARNING "empty CPPUNIT_PREFIX")
        else()        
            set( CppUnit_INCLUDE ${CPPUNIT_PREFIX}/include )
            set( CppUnit_LIBRARY ${CPPUNIT_PREFIX}/lib )
            set( CppUnit_FOUND TRUE )
        endif()
    endif(UNIX)    
endif( CPPUNIT_ROOT_DIR )


include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CppUnit DEFAULT_MSG CppUnit_FOUND CppUnit_INCLUDE CppUnit_LIBRARY)

