
#include "AccountBalanceTest.h"

#include "../core/Account.h"
#include "../core/Transaction.h"


CPPUNIT_TEST_SUITE_REGISTRATION( AccountBalanceTest );



void AccountBalanceTest::LinearBalance()
{
    Account account;
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(0, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(0, 3)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(4, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(50, -45.1f)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-41.10, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(52, 457.5)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(416.40, account.StrikeBalance(), 0.01);
}


void AccountBalanceTest::MixedTimeBalance()
{
    Account account;
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(100, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, account.StrikeBalance(), 0.01);

    account.AddTransaction(t_Transaction_ptr(new Transaction(1000, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(2, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(2000, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(3, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(500, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(4, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(1, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(3000, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(6, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(6, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(7, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(4500, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(8, account.StrikeBalance(), 0.01);

    account.AddTransaction(t_Transaction_ptr(new Transaction(1, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(9, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(3001, 1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, account.StrikeBalance(), 0.01);    
}


void AccountBalanceTest::DuplicatedTransaction()
{
    Account account;
    t_Transaction_ptr pTransaction(new Transaction(1, 2));
    
    account.AddTransaction(pTransaction);
    account.AddTransaction(pTransaction);
    
    CPPUNIT_ASSERT(pTransaction->GetParent() != pTransaction);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(2, account.StrikeBalance(), 0.01);
}





