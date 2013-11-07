//
//  Categiry.cpp
//  DistributedBudget
//
//  Created by Vyacheslav Koscheev on 10/30/13.
//
//

#include "Category.h"
#include "ISerializer.h"




Category::Category()
{}


Category::~Category()
{}


int Category::GetId(t_DistibutedId &refId)
{
    return -1;
}


int Category::Serialize(ISerializer &serializer, int32_t iVersion /*= LAST_SERIALIZE_VERSION*/)
{
	serializer.Serialize(iVersion);

	if (iVersion > LAST_SERIALIZE_VERSION)
		return 1;

	serializer.Serialize(m_strName);
	serializer.Serialize(m_strDescription);
	serializer.Serialize(m_tsModification);

    return 0;
}


