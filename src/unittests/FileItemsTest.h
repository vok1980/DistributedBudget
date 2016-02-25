
#pragma once


#include <../core/types.h>
#include <../core/ISerializer.h>

#include <cppunit/extensions/HelperMacros.h>


class FileItemsTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( FileItemsTest );
    CPPUNIT_TEST( TransactionSaveLoad );
    CPPUNIT_TEST( AccountSaveLoad );
    CPPUNIT_TEST( BudgetSaveLoad );
    CPPUNIT_TEST( CategorySaveLoad );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

public:
    void TransactionSaveLoad();
    void AccountSaveLoad();
    void BudgetSaveLoad();
    void CategorySaveLoad();

private:
	std::shared_ptr<ISerializer> m_saver;
	std::shared_ptr<ISerializer> m_loader;
};
