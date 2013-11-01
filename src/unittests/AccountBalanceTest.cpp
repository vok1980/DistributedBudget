
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
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(50, -45.1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-41.10, account.StrikeBalance(), 0.01);
    
    account.AddTransaction(t_Transaction_ptr(new Transaction(52, 457.5)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(416.40, account.StrikeBalance(), 0.01);
}

