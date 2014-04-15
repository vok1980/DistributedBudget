
#include "ProtoSimpleSerializeTest.h"

#include "../core/Transaction.h"
#include "Transaction.pb.h"


CPPUNIT_TEST_SUITE_REGISTRATION( ProtoSimpleSerializeTest );



void ProtoSimpleSerializeTest::Transaction()
{
	coremess::Transaction bufTransaction;
    t_Transaction_ptr pTransactionOrig(new class Transaction(123, 321));
    t_Transaction_ptr pTransactionStor(new class Transaction(789, 987));
    
    pTransactionOrig->SaveTo(bufTransaction);
    pTransactionStor->LoadFrom(bufTransaction);
    
    t_DistibutedId idOrig, idStor;
    CPPUNIT_ASSERT_EQUAL(0, pTransactionOrig->GetId(idOrig));
    CPPUNIT_ASSERT_EQUAL(0, pTransactionStor->GetId(idStor));
    
    CPPUNIT_ASSERT_EQUAL(idOrig, idStor);
}
