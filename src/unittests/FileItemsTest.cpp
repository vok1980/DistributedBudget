
#include "FileItemsTest.h"

#include "../core/SettingsMng.h"
#include "../core/Transaction.h"

CPPUNIT_TEST_SUITE_REGISTRATION( FileItemsTest );


void FileItemsTest::TransactionSaveLoad()
{
    SettingsMng::Instance().SetItemsDirectory( Poco::Path::temp() );
    t_shared_ptr<ISerializer> saver = SettingsMng::Instance().GetSerializer(ISerializer::SM_SAVER);
    t_shared_ptr<ISerializer> loader = SettingsMng::Instance().GetSerializer(ISerializer::SM_LOADER);
    
    CPPUNIT_ASSERT(saver);
    CPPUNIT_ASSERT(loader);
    
    t_DistibutedId itemId;
    
    Transaction orig(10, 5);
    
    orig.Serialize( *saver );
    CPPUNIT_ASSERT_EQUAL(0, orig.GetId(itemId));
    
    TObjectHolder<Transaction> restored(itemId);
    restored.Serialize(*loader);
    
    CPPUNIT_ASSERT_EQUAL(true, restored.IsSolid());

    CPPUNIT_ASSERT_EQUAL(orig.GetAmount(), restored.GetObject()->GetAmount());
    CPPUNIT_ASSERT_EQUAL(orig.GetTimestamp().epochTime(), restored.GetObject()->GetTimestamp().epochTime() );
}

