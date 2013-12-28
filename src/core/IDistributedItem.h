
#pragma once

#include <string>
#include "types.h"


class ISerializer;


#define LAST_SERIALIZE_VERSION  0



class ISerializable
{
public:
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION) = 0;
};


template <typename pbType>
class IDistributedItem : public ISerializable
{
public:
    typedef pbType t_Buffer;
    
public:
    virtual int GetId(t_DistibutedId &refId) = 0;
    
    virtual int LoadFrom(const t_Buffer&) = 0;
    virtual int SaveTo(t_Buffer&) = 0;
};
