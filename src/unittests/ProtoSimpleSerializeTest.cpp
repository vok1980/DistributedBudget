
#include "ProtoSimpleSerializeTest.h"

#include "../core/Transaction.h"
#include "Transaction.pb.h"

#include "../core/Account.h"
#include "Account.pb.h"

#include "../core/Budget.h"
#include "Budget.pb.h"

#include "../core/Category.h"
#include "Category.pb.h"


CPPUNIT_TEST_SUITE_REGISTRATION( ProtoSimpleSerializeTest );

using namespace core;


void ProtoSimpleSerializeTest::Transaction()
{
	coremess::Transaction bufTransaction;
    t_Transaction_ptr pTransactionOrig(new class Transaction(123, 321));
    t_Transaction_ptr pTransactionStor(new class Transaction(789, 987));
    
    pTransactionOrig->AddCategory("123");
    pTransactionOrig->AddCategory("321");
    
    CPPUNIT_ASSERT_EQUAL(0, pTransactionOrig->SaveTo(bufTransaction));
    CPPUNIT_ASSERT_EQUAL(0, pTransactionStor->LoadFrom(bufTransaction));
    
    t_DistibutedId idOrig, idStor;
    CPPUNIT_ASSERT_EQUAL(0, pTransactionOrig->GetId(idOrig));
    CPPUNIT_ASSERT_EQUAL(0, pTransactionStor->GetId(idStor));
    
    CPPUNIT_ASSERT_EQUAL(idOrig, idStor);
}


void ProtoSimpleSerializeTest::Account()
{
	coremess::Account bufAccount;
    t_Account_ptr pOrig(new class Account());
    t_Account_ptr pStor(new class Account());
    
    t_Transaction_ptr pTransactionOrig(new class Transaction(123, 321));
    pOrig->AddTransaction(pTransactionOrig);
    pOrig->SetName(L"test name");
    pOrig->SetDescription(L"test description");
    
    
    CPPUNIT_ASSERT_EQUAL(0, pOrig->SaveTo(bufAccount));
    CPPUNIT_ASSERT_EQUAL(0, pStor->LoadFrom(bufAccount));
    
    t_DistibutedId idOrig, idStor;
    CPPUNIT_ASSERT_EQUAL(0, pOrig->GetId(idOrig));
    CPPUNIT_ASSERT_EQUAL(0, pStor->GetId(idStor));
    
    CPPUNIT_ASSERT_EQUAL(idOrig, idStor);
}


void ProtoSimpleSerializeTest::Budget()
{
    coremess::Budget bufBudget;
    t_Budget_ptr pOrig(new class Budget());
    t_Budget_ptr pStor(new class Budget());
    
    t_Account_ptr pAccount(new class Account());
    t_Transaction_ptr pTransactionOrig(new class Transaction(123, 321));
    pAccount->AddTransaction(pTransactionOrig);
    pAccount->SetName(L"test name");
    pAccount->SetDescription(L"test description");

    pOrig->AddAccount(pAccount);
    
    CPPUNIT_ASSERT_EQUAL(0, pOrig->SaveTo(bufBudget));
    CPPUNIT_ASSERT_EQUAL(0, pStor->LoadFrom(bufBudget));
    
    t_DistibutedId idOrig, idStor;
    CPPUNIT_ASSERT_EQUAL(0, pOrig->GetId(idOrig));
    CPPUNIT_ASSERT_EQUAL(0, pStor->GetId(idStor));
    
    CPPUNIT_ASSERT_EQUAL(idOrig, idStor);
}


void ProtoSimpleSerializeTest::Category()
{
    coremess::Category bufCategory;
    t_Category_ptr pOrig(new class Category());
    t_Category_ptr pStor(new class Category());
    
    pOrig->SetName(L"test_name");
    pOrig->SetDescription(L"test description");
    
    CPPUNIT_ASSERT_EQUAL(0, pOrig->SaveTo(bufCategory));
    CPPUNIT_ASSERT_EQUAL(0, pStor->LoadFrom(bufCategory));
    
    t_DistibutedId idOrig, idStor;
    CPPUNIT_ASSERT_EQUAL(0, pOrig->GetId(idOrig));
    CPPUNIT_ASSERT_EQUAL(0, pStor->GetId(idStor));
    
    CPPUNIT_ASSERT_EQUAL(idOrig, idStor);
}



