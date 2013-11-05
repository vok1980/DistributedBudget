
#include "Transaction.h"

#define LAST_VERSION 0


Transaction::Transaction(t_timestamp tsEvent, t_money amount) :
	m_tsEvent(tsEvent),
	m_amount(amount)
{}


Transaction::~Transaction()
{}


t_Transaction_ptr Transaction::Embed(t_Transaction_ptr pOldHead)
{
    t_Transaction_ptr pNewHead = shared_from_this();
    
    t_Transaction_ptr pNewParent = pOldHead;
    t_Transaction_ptr pNewChild;
    
    if ( pOldHead && pOldHead->m_tsEvent > m_tsEvent )
    {
        pNewChild = pNewParent;
        pNewParent = pNewParent->m_pParentTransaction;
        pNewHead = pOldHead;
    }
    
    shared_from_this()->m_pParentTransaction = pNewParent;
    
    if (pNewChild)
    {
        pNewChild->m_pParentTransaction = shared_from_this();
    }
    
    return pNewHead;
}


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


void Transaction::SetParent(t_Transaction_ptr pParent)
{
	m_pParentTransaction = pParent;
}




