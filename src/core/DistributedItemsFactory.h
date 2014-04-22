
#pragma once

//#include <list>
#include <deque>

#include "types.h"
#include "TObjectHolder.h"
#include "serializers/FileLoadSerializer.h"


template <typename TDistributedItem>
class TDistributedItemsFactory
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
	FileLoadSerializer loader("/temp");
	TObjectHolder<TDistributedItem> holder(idItem);
	holder.Serialize(loader);
	m_aCollection.push_back(holder.GetObject());
	return holder.GetObject();
}


