
#include "MemSerializerTest.h"

#include "../core/serializers/MemSaveSerializer.h"
#include "../core/serializers/MemLoadSerializer.h"

CPPUNIT_TEST_SUITE_REGISTRATION( MemSerializerTest );


void MemSerializerTest::SavedSize()
{
	MemSaveSerializer saver;
	MemLoadSerializer loader;
}
