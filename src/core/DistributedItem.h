
#pragma once

#include <string>
#include <cassert>

#include "types.h"


//class ISerializer;
#include "ISerializer.h"





class ISerializable
{
public:
    virtual int Serialize(ISerializer&) = 0;
};


template <typename pbType>
class DistributedItem : public ISerializable
{
public:
    typedef pbType t_Buffer;
    
public:
    virtual int Serialize(ISerializer&);
    
public:
    virtual int GetId(t_DistibutedId &refId) = 0;
    
    virtual int LoadFrom(const t_Buffer&) = 0;
    virtual int SaveTo(t_Buffer&) = 0;
};


template <typename pbType>
int DistributedItem<pbType>::Serialize(ISerializer &serializer)
{
    int iRet = -1;
    t_DistibutedId id;
    GetId(id);
    
    t_Buffer protobuf;
    
    switch (serializer.GetMode())
    {
        case ISerializer::SM_SAVER:
            iRet = SaveTo(protobuf);
            serializer.Serialize(protobuf, id);
            break;
            
        case ISerializer::SM_LOADER:
            serializer.Serialize(protobuf, id);
            iRet = LoadFrom(protobuf);
            break;
            
        default:
            assert(!"unexpected serializer mode");
    }
    
    return iRet;
}

