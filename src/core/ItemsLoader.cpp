
#include "ItemsLoader.h"

#include "serializers/FileLoadSerializer.h"
#include "DistributedItem.h"



int ItemsLoader::Load(ISerializable& item)
{
    FileLoadSerializer loader(".temp/");
    item.Serialize(loader);
    
    return 0;
}


