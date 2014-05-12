
#include "FileItemsTest.h"

#include "../core/SettingsMng.h"

CPPUNIT_TEST_SUITE_REGISTRATION( FileItemsTest );


void FileItemsTest::TransactionSaveLoad()
{
    SettingsMng::Instance().GetSerializer(ISerializer::SM_SAVER);
    SettingsMng::Instance().GetSerializer(ISerializer::SM_LOADER);
}

