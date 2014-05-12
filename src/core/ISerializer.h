
#pragma once

#include <set>
#include <string>

#include <google/protobuf/message.h>

#include "types.h"
#include "IBalanceStriker.h"


class ISerializer
{
public:
    virtual ~ISerializer(){};
    
public:
    enum SerializeMode
    {
        SM_LOADER,
        SM_SAVER
    };
    
    virtual SerializeMode GetMode(void) = 0;
    virtual void Serialize(::google::protobuf::Message&, const t_DistibutedId &id) = 0;
};
