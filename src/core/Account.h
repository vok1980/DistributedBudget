
#pragma once

#include <memory>

#include "IDistributedItem.h"
#include "types.h"


class Account : public IDistributedItem
{
public:
	Account();
	virtual ~Account();

public:
    virtual int GetId(t_DistibutedId &refId);
    void AddTransaction(t_Transaction_ptr pTransaction);
    t_money StrikeBalance(void);
    
private:
    t_Transaction_ptr m_pHeadTrunsuction;
};


typedef std::tr1::shared_ptr<Account> t_Account_ptr;
