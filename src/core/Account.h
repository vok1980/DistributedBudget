
#pragma once

#include <memory>

#include "IDistributedItem.h"
#include "Transaction.h"

//class Transaction;


class Account : public IDistributedItem
{
public:
    virtual int GetSha(std::string &strSha);
//    void AddTransaction(std::shared_ptr<Transaction>);
};
