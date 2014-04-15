//
//  Categiry.cpp
//  DistributedBudget
//
//  Created by Vyacheslav Koscheev on 10/30/13.
//
//

#include "Category.h"
#include "ISerializer.h"

#include "SHA1EngineExt.h"




Category::Category()
{}


Category::~Category()
{}


int Category::GetId(t_DistibutedId &refId)
{
    SHA1EngineExt engine(refId);

    engine.update(m_strName);
    engine.update(m_strDescription);
    engine.update(m_tsModification);

    return 0;
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


void Category::SetName(const std::wstring &_name)
{
    m_strName = _name;
}


std::wstring Category::GetName() const
{
    return m_strName;
}


void Category::SetDescription(const std::wstring &_description)
{
    m_strDescription = _description;
}


std::wstring Category::GetDescription() const
{
    return m_strDescription;
}


int Category::LoadFrom(const t_Buffer&)
{
    return -1;
}


int Category::SaveTo(t_Buffer&)
{
    return -1;
}



