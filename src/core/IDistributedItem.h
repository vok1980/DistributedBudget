
#pragma once

#include <string>

#include "types.h"
#include "ISerializer.h"


class IDistributedItem
{
public:
    virtual int GetId(t_id &refId) = 0;
    virtual int Serialize(ISerializer&) = 0;
};
