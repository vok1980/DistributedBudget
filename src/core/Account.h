
#pragma once

#include <memory>

#include "IDistributedItem.h"
#include "types.h"


class Account : public IDistributedItem
{
public:
    virtual int GetId(t_id &refId);
    void AddTransaction(t_Transaction_ptr pTransaction);
    void RemoveTransaction(t_Transaction_ptr pTransaction);
};
