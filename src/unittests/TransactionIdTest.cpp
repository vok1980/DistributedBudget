
#include "TransactionIdTest.h"

#include "../core/Transaction.h"


CPPUNIT_TEST_SUITE_REGISTRATION( TransactionIdTest );



void TransactionIdTest::NonEmpty(void)
{
    Transaction transaction(0, 0);
    t_DistibutedId transactionId;
    
    transaction.GetId(transactionId);
    CPPUNIT_ASSERT( !transactionId.empty() );
}


void TransactionIdTest::ParentChange(void)
{
    t_Transaction_ptr pTransaction00(new Transaction(12, 34));
    t_Transaction_ptr pTransaction01(new Transaction(56, 78));
    
    t_DistibutedId transactionId01_old;
    t_DistibutedId transactionId01_new;
    
    pTransaction01->GetId(transactionId01_old);
    pTransaction01->Embed(pTransaction00);
    pTransaction01->GetId(transactionId01_new);
    
    CPPUNIT_ASSERT(transactionId01_old != transactionId01_new);
}

