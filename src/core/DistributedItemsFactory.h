
#pragma once

#include <list>
//#include <deque>
#include <algorithm>

#include "types.h"
#include "TObjectHolder.h"
#include "serializers/FileLoadSerializer.h"
#include "SettingsMng.h"

#include "../tools/Singleton.h"


template <typename TDistributedItem>
class TDistributedItemsFactory : public Singleton<TDistributedItemsFactory<TDistributedItem> >
{
public:
    virtual ~TDistributedItemsFactory(){};
    
	t_shared_ptr<TDistributedItem> CreateObject();
	t_shared_ptr<TDistributedItem> CreateObject(const t_DistibutedId&);
    
    virtual int Serialize(ISerializer&);

private:
	typedef std::list<t_weak_ptr<TDistributedItem> > t_objects;
	t_objects m_aCollection;
};





template <typename TDistributedItem>
t_shared_ptr<TDistributedItem> TDistributedItemsFactory<TDistributedItem>::CreateObject()
{
	t_shared_ptr<TDistributedItem> obj(new TDistributedItem());
	m_aCollection.push_back(obj);
	return obj;
}


template <typename TDistributedItem>
t_shared_ptr<TDistributedItem> TDistributedItemsFactory<TDistributedItem>::CreateObject(const t_DistibutedId &idItem)
{
    assert(!idItem.empty());
    
	TObjectHolder<TDistributedItem> holder(idItem);
    t_shared_ptr<ISerializer> pSerializer = SettingsMng::Instance().GetSerializer(ISerializer::SM_LOADER);
    
    if (pSerializer)
    {
        holder.Serialize( *pSerializer.get() );
    
        if (holder.IsSolid())
            m_aCollection.push_back(holder.GetObject());
    }
    
	return holder.GetObject();
}


template <typename TDistributedItem>
int TDistributedItemsFactory<TDistributedItem>::Serialize(ISerializer &serializer)
{
    int iRet = 0;
    std::for_each(m_aCollection.begin(), m_aCollection.end(),
                  [&serializer, &iRet](const typename t_objects::value_type &val)
                  {
                      t_shared_ptr<TDistributedItem> ptr = val.lock();
                      
                      if (ptr)
                          iRet += ptr->Serialize(serializer);
                  }
            );
    return iRet;
}


