
#pragma once

#include <list>
//#include <deque>
#include <algorithm>

#include "types.h"
#include "TObjectHolder.h"
#include "serializers/FileLoadSerializer.h"
#include "SettingsMng.h"
#include "DistributedItemsFactoryCtrl.h"

#include "../tools/Singleton.h"


namespace core {
    

template <typename TDistributedItem>
class TDistributedItemsFactory : public Singleton<TDistributedItemsFactory<TDistributedItem> >, public DistributedItemsFactoryCtrl
{
    typedef std_shared::shared_ptr<TDistributedItem> t_shared_item;
    typedef std_shared::weak_ptr<TDistributedItem> t_weak_item;
    
public:
    virtual ~TDistributedItemsFactory(){};
    
    t_shared_item CreateObject();
    t_shared_item CreateObject(const t_DistibutedId&);
    void Register(t_shared_item pItem);
    
    virtual int Serialize(ISerializer&);

private:
	typedef std::set<t_weak_item> t_objects;
	t_objects m_aCollection;
};





template <typename TDistributedItem>
std_shared::shared_ptr<TDistributedItem> TDistributedItemsFactory<TDistributedItem>::CreateObject()
{
	std_shared::shared_ptr<TDistributedItem> obj(new TDistributedItem());
	Register(obj);
	return obj;
}


template <typename TDistributedItem>
std_shared::shared_ptr<TDistributedItem> TDistributedItemsFactory<TDistributedItem>::CreateObject(const t_DistibutedId &idItem)
{
    assert(!idItem.empty());
    
	TObjectHolder<TDistributedItem> holder(idItem);
	std_shared::shared_ptr<ISerializer> pSerializer = SettingsMng::Instance().GetSerializer(ISerializer::SM_LOADER);
    
    if (pSerializer)
    {
        holder.Serialize( *pSerializer.get() );
    
        if (holder.IsSolid())
            Register(holder.GetObject());
    }
    
	return holder.GetObject();
}


template <typename TDistributedItem>
void TDistributedItemsFactory<TDistributedItem>::Register(t_shared_item pItem)
{
    m_aCollection.insert(pItem);
}
    

template <typename TDistributedItem>
int TDistributedItemsFactory<TDistributedItem>::Serialize(ISerializer &serializer)
{
    int iRet = 0;
    std::for_each(m_aCollection.begin(), m_aCollection.end(),
                  [&serializer, &iRet](const typename t_objects::value_type &val)
                  {
    				  std_shared::shared_ptr<TDistributedItem> ptr = val.lock();
                      
                      if (ptr)
                          iRet += ptr->Serialize(serializer);
                  }
            );
    return iRet;
}
    
};



