
#pragma once

#include <string>

//#include "types.h"
//#include "ISerializer.h"

class ISerializer;


typedef std::string t_DistibutedId;

#define LAST_SERIALIZE_VERSION  1


class IDistributedItem
{
public:
    virtual int GetId(t_DistibutedId &refId) = 0;
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION) = 0;
};
