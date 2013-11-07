
#include "Transaction.h"

#include <Poco/SHA1Engine.h>




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
        pNewParent = pNewParent->m_parentTransaction.GetObject();
        pNewHead = pOldHead;
    }
    
    if (pNewParent != shared_from_this())
    {
        shared_from_this()->m_parentTransaction = pNewParent;
    
        if (pNewChild)
        {
            pNewChild->m_parentTransaction = shared_from_this();
        }
    }
    
    return pNewHead;
}


int Transaction::GetId(t_DistibutedId &refId)
{
    Poco::SHA1Engine engine;
  
    t_DistibutedId parentId;
    m_parentTransaction.GetObject(parentId);
    
    engine.update(parentId);
    engine.update(&m_tsEvent, sizeof(m_tsEvent));
    engine.update(&m_amount, sizeof(m_amount));
//    engine.update(m_strName);
//    engine.update(m_strComment);
    
    for ( t_CategoryColl::iterator it = m_aCategory.begin(); it != m_aCategory.end(); ++it )
    {
//        engine.update( *it );
    }
    
    const Poco::DigestEngine::Digest &digest = engine.digest();
    refId = Poco::DigestEngine::digestToHex(digest);
    
    return 0;
}


int Transaction::Serialize(ISerializer &serializer, int32_t iVersion /*= LAST_SERIALIZE_VERSION*/)
{
	serializer.Serialize(iVersion);
    
    if (iVersion > LAST_SERIALIZE_VERSION)
        return 1;    
    
	serializer.Serialize(m_tsEvent);
	serializer.Serialize(m_amount);
	serializer.Serialize(m_strName);
	serializer.Serialize(m_strComment);

    int32_t iSize = m_aCategory.size();
    serializer.Serialize(iSize);
    m_aCategory.resize(iSize);
    
    for (int lc = 0; lc < iSize; ++lc)
    {
        m_aCategory[lc].Serialize(serializer);    
    }
    
    m_parentTransaction.Serialize(serializer);
    
	return 0;
}


t_money Transaction::GetAmount(void)
{
	return m_amount;
}


t_Transaction_ptr Transaction::GetParent(void)
{
	return m_parentTransaction.GetObject();
}


void Transaction::SetParent(t_Transaction_ptr pParent)
{
	m_parentTransaction = pParent;
}




