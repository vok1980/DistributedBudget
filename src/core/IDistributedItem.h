
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


class IDistributedItem : public ISerializable
{
public:
    virtual int GetId(t_DistibutedId &refId) = 0;
};
