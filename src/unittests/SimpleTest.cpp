
#include "SimpleTest.h"

#include <vector>
#include <stdexcept>
#include <cppunit/extensions/HelperMacros.h>



CPPUNIT_TEST_SUITE_REGISTRATION( SimpleTest );



void SimpleTest::setUp()
{}


void SimpleTest::tearDown()
{}


void SimpleTest::testOne()
{
    CPPUNIT_ASSERT(true);
    CPPUNIT_ASSERT(1+1==2);
    CPPUNIT_ASSERT_ASSERTION_FAIL ( CPPUNIT_FAIL("asdfgh") );
    CPPUNIT_ASSERT_ASSERTION_PASS ( CPPUNIT_ASSERT(1 == 1) );
}



void SimpleTest::testTwo()
{
    CPPUNIT_ASSERT_EQUAL(100/4, 5*5);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("qwerty", 2, 2);
}



void SimpleTest::testThree()
{
    std::vector<int> v;
    CPPUNIT_ASSERT_THROW( v.at( 50 ), std::out_of_range );
}

