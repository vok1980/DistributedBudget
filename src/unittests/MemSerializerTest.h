
#pragma once

#include <cppunit/extensions/HelperMacros.h>

class MemSerializerTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( MemSerializerTest );
    CPPUNIT_TEST( SavedSize );
    CPPUNIT_TEST_SUITE_END();
public:
    void SavedSize();
};
