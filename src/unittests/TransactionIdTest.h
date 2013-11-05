
#pragma once


#include <cppunit/extensions/HelperMacros.h>

class TransactionIdTest : public CppUnit::TestFixture
{
public:
    CPPUNIT_TEST_SUITE( TransactionIdTest );
    
    CPPUNIT_TEST( NonEmpty );
    CPPUNIT_TEST( ParentChange );
    
    CPPUNIT_TEST_SUITE_END();
    
private:
    void NonEmpty(void);
    void ParentChange(void);
};

