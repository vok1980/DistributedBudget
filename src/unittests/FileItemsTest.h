
#pragma once


#include <cppunit/extensions/HelperMacros.h>

class FileItemsTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( FileItemsTest );
    CPPUNIT_TEST( TransactionSaveLoad );
    CPPUNIT_TEST_SUITE_END();
public:
    void TransactionSaveLoad();
};
