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
#include "Category.pb.h"



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


#define MAX_W_CHARS 1024
#define MAX_MB_CHARS (2 * MAX_W_CHARS)


int Category::LoadFrom(const t_Buffer &protobuf)
{
    wchar_t buffer[MAX_W_CHARS];
    
    mbstowcs(buffer, protobuf.name().c_str(), MAX_W_CHARS);
    m_strName = buffer;
    mbstowcs(buffer, protobuf.description().c_str(), MAX_W_CHARS);
    m_strDescription = buffer;
    
	m_tsModification = protobuf.modification();
    
    return 0;
}


int Category::SaveTo(t_Buffer &protobuf)
{
    char buffer[MAX_MB_CHARS];
    
    wcstombs(buffer, m_strName.c_str(), MAX_MB_CHARS);
    protobuf.set_name(buffer);
    
    wcstombs(buffer, m_strDescription.c_str(), MAX_MB_CHARS);
    protobuf.set_description(buffer);
	
    protobuf.set_modification(m_tsModification.epochMicroseconds());
    
    return 0;
}



