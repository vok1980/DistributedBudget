
#pragma once 

#include <memory>
#include "../tools/Singleton.h"
#include "ISerializer.h"

//class ISerializable;

#include "Poco/Path.h"


namespace core {

class SettingsMng : public Singleton<SettingsMng>
{
public:
    SettingsMng();
    
public:
    void SetItemsDirectory( const Poco::Path& pathToItems );
	std::shared_ptr<ISerializer> GetSerializer(ISerializer::SerializeMode mode);
    
private:
    Poco::Path m_itemsDirectory;
};


};

