
#pragma once

#include <cppunit/extensions/HelperMacros.h>

class ProtoSimpleSerializeTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( ProtoSimpleSerializeTest );
    CPPUNIT_TEST( Transaction );
    CPPUNIT_TEST( Account );
    CPPUNIT_TEST( Budget );
    CPPUNIT_TEST( Category );
    CPPUNIT_TEST_SUITE_END();
public:
    void Transaction();
    void Account();
    void Budget();
    void Category();
};
