
#pragma once


#include <cppunit/extensions/HelperMacros.h>


class SimpleTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( SimpleTest );
    
    CPPUNIT_TEST( testOne );
    CPPUNIT_TEST( testTwo );
    CPPUNIT_TEST( testThree );
    
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp();
    void tearDown();

private:
    void testOne();
    void testTwo();
    void testThree();
    
};
