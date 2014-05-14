
#include "SettingsMng.h"

#include "serializers/FileLoadSerializer.h"
#include "serializers/FileSaveSerializer.h"
#include "DistributedItem.h"

#include "Poco/Path.h"
#include "Poco/File.h"


namespace core {

SettingsMng::SettingsMng()
{
//    SetItemsDirectory( Poco::Path::temp() );
    SetItemsDirectory( Poco::Path::current() );
}


void SettingsMng::SetItemsDirectory( const Poco::Path& pathToItems )
{
    m_itemsDirectory = pathToItems;
    m_itemsDirectory.append("items");
}


t_shared_ptr<ISerializer> SettingsMng::GetSerializer(ISerializer::SerializeMode mode)
{
    Poco::File directory(m_itemsDirectory);
    directory.createDirectory();
    
    switch (mode)
    {
        case  ISerializer::SM_LOADER:
            return t_shared_ptr<ISerializer>( new FileLoadSerializer( m_itemsDirectory ) );
            
        case  ISerializer::SM_SAVER:
            return t_shared_ptr<ISerializer>( new FileSaveSerializer( m_itemsDirectory ) );

    };
    
    return t_shared_ptr<ISerializer>();
}

    
};

