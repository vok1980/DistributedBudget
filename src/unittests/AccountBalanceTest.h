
#pragma once


#include <cppunit/extensions/HelperMacros.h>


class AccountBalanceTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( AccountBalanceTest );
    
    CPPUNIT_TEST( LinearBalance );
    CPPUNIT_TEST( MixedTimeBalance );
    CPPUNIT_TEST( DuplicatedTransaction );
      
    CPPUNIT_TEST_SUITE_END();
    
private:
    void LinearBalance();
    void MixedTimeBalance();
    void DuplicatedTransaction();

};