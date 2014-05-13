
#include "FileItemsTest.h"

#include "../core/SettingsMng.h"
#include "../core/Transaction.h"
#include "../core/Account.h"
#include "../core/Budget.h"
#include "../core/Category.h"


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
    orig.SetName(L"qwerty");
    orig.SetComment(L"asdfgh");
    orig.AddCategory("test_category_id");
    
    orig.Serialize( *saver );
    CPPUNIT_ASSERT_EQUAL(0, orig.GetId(itemId));
    
    TObjectHolder<Transaction> restored(itemId);
    restored.Serialize(*loader);
    
    CPPUNIT_ASSERT_EQUAL(true, restored.IsSolid());

    CPPUNIT_ASSERT_EQUAL(orig.GetAmount(), restored.GetObject()->GetAmount());
    CPPUNIT_ASSERT_EQUAL(orig.GetTimestamp().epochTime(), restored.GetObject()->GetTimestamp().epochTime() );
    CPPUNIT_ASSERT (orig.GetName() == restored.GetObject()->GetName());
    CPPUNIT_ASSERT (orig.GetComment() == restored.GetObject()->GetComment());
}


void FileItemsTest::AccountSaveLoad()
{
    SettingsMng::Instance().SetItemsDirectory( Poco::Path::temp() );
    t_shared_ptr<ISerializer> saver = SettingsMng::Instance().GetSerializer(ISerializer::SM_SAVER);
    t_shared_ptr<ISerializer> loader = SettingsMng::Instance().GetSerializer(ISerializer::SM_LOADER);
    
    CPPUNIT_ASSERT(saver);
    CPPUNIT_ASSERT(loader);
    
    t_Transaction_ptr pTrans(new Transaction(100, 500));
    pTrans->SetName(L"qwerty0");
    pTrans->SetComment(L"asdfgh0");
    pTrans->AddCategory("test_category_id0");
    
    Account orig;
    orig.AddTransaction(pTrans);
    orig.SetName(L"3edc");
    orig.SetDescription(L"1qaz");
    
    t_DistibutedId origId, restId;
    CPPUNIT_ASSERT_EQUAL(0, orig.GetId(origId));
    
    TObjectHolder<Account> restored(origId);
    CPPUNIT_ASSERT_EQUAL(false, restored.IsSolid());
    
    CPPUNIT_ASSERT_EQUAL(0, orig.Serialize(*saver));
    CPPUNIT_ASSERT_EQUAL(0, pTrans->Serialize(*saver));
    CPPUNIT_ASSERT_EQUAL(0, restored.Serialize(*loader));
    
    CPPUNIT_ASSERT_EQUAL(true, restored.IsSolid());
    CPPUNIT_ASSERT_EQUAL(0, restored.GetId(restId));
    CPPUNIT_ASSERT_EQUAL(origId, restId);
    
    CPPUNIT_ASSERT_EQUAL(orig.StrikeBalance(), restored.GetObject()->StrikeBalance());
}


void FileItemsTest::BudgetSaveLoad()
{
}


void FileItemsTest::CategorySaveLoad()
{
}


