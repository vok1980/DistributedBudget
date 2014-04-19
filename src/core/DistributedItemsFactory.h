
#pragma once

#include "types.h"
#include "TObjectHolder.h"
#include "serializers/FileLoadSerializer.h"


class DistributedItemsFactory
{
public:
	template <typename TDistributedItem>
	t_shared_ptr<TDistributedItem> CreateObject();

	template <typename TDistributedItem>
	t_shared_ptr<TDistributedItem> CreateObject(const t_DistibutedId&);
};


template <typename TDistributedItem>
t_shared_ptr<TDistributedItem> DistributedItemsFactory::CreateObject()
{
	return t_shared_ptr<TDistributedItem>(new TDistributedItem());
}


template <typename TDistributedItem>
t_shared_ptr<TDistributedItem> CreateObject(const t_DistibutedId &idItem)
{
	FileLoadSerializer loader("/temp");
	TObjectHolder<TDistributedItem> holder(idItem);
	holder.Serialize(loader);

	return holder.GetObject();
}


