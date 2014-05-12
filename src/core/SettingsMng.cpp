
#include "SettingsMng.h"

#include "serializers/FileLoadSerializer.h"
#include "serializers/FileSaveSerializer.h"
#include "DistributedItem.h"




SettingsMng::SettingsMng() :
    m_strItemsDirectory(".items")
{
}


t_shared_ptr<ISerializer> SettingsMng::GetSerializer(ISerializer::SerializeMode mode)
{
    switch (mode)
    {
        case  ISerializer::SM_LOADER:
            return t_shared_ptr<ISerializer>( new FileLoadSerializer( m_strItemsDirectory ) );
            
        case  ISerializer::SM_SAVER:
            return t_shared_ptr<ISerializer>( new FileSaveSerializer( m_strItemsDirectory ) );

    };
    
    return t_shared_ptr<ISerializer>();
}

