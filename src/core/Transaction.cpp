
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


void Transaction::AddCategory(t_DistibutedId refCatId)
{
    m_aCategory.push_back( TObjectHolder<Category>(refCatId) );
}


#define MAX_W_CHARS 1024
#define MAX_MB_CHARS (2 * MAX_W_CHARS)


int Transaction::LoadFrom(const t_Buffer &protobuf)
{
    m_parentTransaction.SetObject(protobuf.parent());
    m_amount = protobuf.amount();
    m_tsEvent = protobuf.timestamp();
    
    wchar_t buffer[MAX_W_CHARS];
    
    mbstowcs(buffer, protobuf.name().c_str(), MAX_W_CHARS);
    m_strName = buffer;
    mbstowcs(buffer, protobuf.description().c_str(), MAX_W_CHARS);
    m_strComment = buffer;
    
    return 0;
}


int Transaction::SaveTo(t_Buffer &protobuf)
{
    t_DistibutedId id;

    if ( NULL != GetParent() && 0 == GetParent()->GetId(id) )
    {
        protobuf.set_parent( id );
    }

    protobuf.set_timestamp(m_tsEvent.epochMicroseconds());
    protobuf.set_amount(m_amount);

    char buffer[MAX_MB_CHARS];
    
    wcstombs(buffer, m_strName.c_str(), MAX_MB_CHARS);
    protobuf.set_name(buffer);
    
    wcstombs(buffer, m_strComment.c_str(), MAX_MB_CHARS);
    protobuf.set_description(buffer);
    
    std::for_each( m_aCategory.begin(), m_aCategory.end(),
                  [&protobuf, &id](t_CategoryColl::value_type &category)
                  {
                      if (0 == category.GetId(id))
                      {
                          protobuf.add_category(id);
                      }
                  }
                  );

    return 0;
}





