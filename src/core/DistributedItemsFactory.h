
#pragma once

//#include <list>
#include <deque>

#include "types.h"
#include "TObjectHolder.h"
#include "serializers/FileLoadSerializer.h"
#include "ItemsLoader.h"

#include "../tools/Singleton.h"


template <typename TDistributedItem>
class TDistributedItemsFactory : public ItemsLoader, public Singleton<TDistributedItemsFactory<TDistributedItem> >
{
public:
	t_shared_ptr<TDistributedItem> CreateObject();
	t_shared_ptr<TDistributedItem> CreateObject(const t_DistibutedId&);

private:
	typedef std::deque<t_weak_ptr<TDistributedItem> > t_objects;
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
	TObjectHolder<TDistributedItem> holder(idItem);
    Load(holder);
    
    if (holder.IsSolid())
        m_aCollection.push_back(holder.GetObject());
    
	return holder.GetObject();
}


