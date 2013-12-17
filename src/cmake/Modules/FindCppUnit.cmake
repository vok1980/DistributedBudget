

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

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CppUnit DEFAULT_MSG CppUnit_FOUND CppUnit_INCLUDE CppUnit_LIBRARY)

