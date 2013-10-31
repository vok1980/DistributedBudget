
#pragma once

#include <string>

#include "types.h"
#include "ISerializer.h"


typedef std::string t_DistibutedId;


class IDistributedItem
{
public:
    virtual int GetId(t_DistibutedId &refId) = 0;
    virtual int Serialize(ISerializer&) = 0;
};
