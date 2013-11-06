
#include "BudgetBalanceTest.h"

#include "../core/Budget.h"
#include "../core/Account.h"
#include "../core/Transaction.h"


CPPUNIT_TEST_SUITE_REGISTRATION( BudgetBalanceTest );



void BudgetBalanceTest::SingleAccountBalance(void)
{
    Budget budget;
    t_Account_ptr pFirstAccount(new Account());
    
    budget.AddAccount(pFirstAccount);
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, budget.StrikeBalance(), 0.01);
    
    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(0, 1.0)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, budget.StrikeBalance(), 0.01);
    
    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(0, 10.0)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(11, budget.StrikeBalance(), 0.01);
    
    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(0, 1.1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(12.1, budget.StrikeBalance(), 0.01);
    
    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(0, -5.4)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(6.7, budget.StrikeBalance(), 0.01);
}


void BudgetBalanceTest::DoubleAccountBalance(void)
{
    Budget budget;
    t_Account_ptr pFirstAccount(new Account());
    t_Account_ptr pSecondAccount(new Account());
    
    budget.AddAccount(pFirstAccount);
    budget.AddAccount(pSecondAccount);
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, budget.StrikeBalance(), 0.01);
    
    pSecondAccount->AddTransaction(t_Transaction_ptr(new Transaction(0, 1.0)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, budget.StrikeBalance(), 0.01);
    
    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(100, 6.0)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(7, budget.StrikeBalance(), 0.01);
    
    pSecondAccount->AddTransaction(t_Transaction_ptr(new Transaction(50, 8.0)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(15, budget.StrikeBalance(), 0.01);
    
    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(20, 39.5)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(54.5, budget.StrikeBalance(), 0.01);
    
    pSecondAccount->AddTransaction(t_Transaction_ptr(new Transaction(30, -45.2)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(9.3, budget.StrikeBalance(), 0.01);
    
    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(30, 14.1)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(23.4, budget.StrikeBalance(), 0.01);
    
    pSecondAccount->AddTransaction(t_Transaction_ptr(new Transaction(101, -500.4)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-477, budget.StrikeBalance(), 0.01);

    pFirstAccount->AddTransaction(t_Transaction_ptr(new Transaction(101, 477.0)));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, budget.StrikeBalance(), 0.01);
    
}

