
#pragma once 

#include "../tools/Singleton.h"
#include "ISerializer.h"

//class ISerializable;


class SettingsMng : public Singleton<SettingsMng>
{
public:
    SettingsMng();
    
public:
	t_shared_ptr<ISerializer> GetSerializer(ISerializer::SerializeMode mode);
    
private:
    std::string m_strItemsDirectory;
};

