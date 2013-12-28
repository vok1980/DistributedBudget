
#include "Transaction.h"

#include <algorithm>
#include "SHA1EngineExt.h"
#include "Transaction.pb.h"



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
    SHA1EngineExt engine(refId);
  
    t_DistibutedId parentId;
    m_parentTransaction.GetObject(parentId);
    
    engine.update(parentId);
    engine.update(m_tsEvent);
    engine.update(m_amount);
    engine.update(m_strName);
    engine.update(m_strComment);
    
    std::for_each( m_aCategory.begin(), m_aCategory.end(),
    		[&engine](t_CategoryColl::value_type &category)
    		{
    			t_DistibutedId catId;
    			category.GetId(catId);
    			engine.update(catId);
    		}
    );

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


int Transaction::LoadFrom(const t_Buffer &refBuffer)
{
//    refBuffer.parent();
    refBuffer.name();
    refBuffer.amount();
    return -1;
}


int Transaction::SaveTo(t_Buffer &refBuffer)
{
//    refBuffer.mutable_parent();

    refBuffer.set_timestamp(m_tsEvent.epochMicroseconds());
    refBuffer.set_amount(m_amount);
//    refBuffer.set_name(m_strName);
//    refBuffer.set_description(<#const ::std::string &value#>)
    return -1;
}





