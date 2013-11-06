

#pragma once


#include <cppunit/extensions/HelperMacros.h>


class BudgetBalanceTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( BudgetBalanceTest );
    
    CPPUNIT_TEST( SingleAccountBalance );
    CPPUNIT_TEST( DoubleAccountBalance );
    
    CPPUNIT_TEST_SUITE_END();
    
private:
    void SingleAccountBalance(void);
    void DoubleAccountBalance(void);
   
};
