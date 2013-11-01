
#pragma once


#include <cppunit/extensions/HelperMacros.h>


class AccountBalanceTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( AccountBalanceTest );
    
    CPPUNIT_TEST( LinearBalance );
  
    
    CPPUNIT_TEST_SUITE_END();
    
private:
    void LinearBalance();

};