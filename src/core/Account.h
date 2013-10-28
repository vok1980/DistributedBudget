
#pragma once

#include <memory>

#include "IDistributedItem.h"
#include "types.h"


class Account : public IDistributedItem
{
public:
    virtual int GetSha(std::string &strSha);
    void AddTransaction(t_Transaction_ptr pTransuction);
    void RemoveTransaction(t_Transaction_ptr pTransuction);
};
