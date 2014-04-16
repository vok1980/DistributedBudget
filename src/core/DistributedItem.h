
#pragma once

#include <string>
#include <cassert>

#include "types.h"


//class ISerializer;
#include "ISerializer.h"


#define LAST_SERIALIZE_VERSION  0



class ISerializable
{
public:
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION) = 0;
};


template <typename pbType>
class DistributedItem : public ISerializable
{
public:
    typedef pbType t_Buffer;
    
public:
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION);
    
public:
    virtual int GetId(t_DistibutedId &refId) = 0;
    
    virtual int LoadFrom(const t_Buffer&) = 0;
    virtual int SaveTo(t_Buffer&) = 0;
};


template <typename pbType>
int DistributedItem<pbType>::Serialize(ISerializer &serializer, int32_t iVersion)
{
    t_Buffer protobuf;
    
    switch (serializer.GetMode())
    {
        case ISerializer::SM_SAVER:
            SaveTo(protobuf);
            serializer.Serialize(protobuf);
            break;
            
        case ISerializer::SM_LOADER:
            serializer.Serialize(protobuf);
            LoadFrom(protobuf);
            break;
            
        default:
            assert(!"unexpected serializer mode");
    }
    
    return -1;
}

