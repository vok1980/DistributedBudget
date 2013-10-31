
#include "Transaction.h"

#define LAST_VERSION 0


Transaction::Transaction()
{}


Transaction::~Transaction()
{}


int Transaction::GetId(t_DistibutedId &refId)
{
    return 0;
}


int Transaction::Serialize(ISerializer &serializer)
{
	int32_t iVersion = LAST_VERSION;
 
	serializer.Serialize(iVersion);
	serializer.Serialize(m_tsEvent);
	serializer.Serialize(m_amount);
	serializer.Serialize(m_strName);
	serializer.Serialize(m_strComment);
//	serializer.Serialize(m_aCategory);

	return -1;
}


t_money Transaction::GetAmount(void)
{
	return m_amount;
}


t_Transaction_ptr Transaction::GetParent(void)
{
	return m_pParentTransaction;
}


