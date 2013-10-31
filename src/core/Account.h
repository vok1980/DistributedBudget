
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
    
private:
    t_Transaction_ptr m_pHeadTrunsuction;
};


typedef std::tr1::shared_ptr<Account> t_Account_ptr;
