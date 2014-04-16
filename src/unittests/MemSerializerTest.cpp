
#include "MemSerializerTest.h"

#include "../core/serializers/MemSaveSerializer.h"
#include "../core/serializers/MemLoadSerializer.h"

#include "../core/Transaction.h"


CPPUNIT_TEST_SUITE_REGISTRATION( MemSerializerTest );


void MemSerializerTest::TransactionSaveLoad()
{
    t_Transaction_ptr pTransaction00(new Transaction(12, 34));
    t_Transaction_ptr pTransaction01(new Transaction(21, 43));
    
    std::ostringstream outstream;
	MemSaveSerializer saver(&outstream);
    pTransaction00->Serialize(saver);
    
    std::istringstream instream(outstream.str());
	MemLoadSerializer loader(&instream);
    
    t_DistibutedId id00, id01;
    CPPUNIT_ASSERT_EQUAL(0, pTransaction00->GetId(id00));
    CPPUNIT_ASSERT_EQUAL(0, pTransaction01->GetId(id01));
    CPPUNIT_ASSERT(id00 != id01);
    
    pTransaction01->Serialize(loader);
    
    pTransaction01->GetId(id01);
    CPPUNIT_ASSERT_EQUAL(id00, id01);
}


