
#pragma once

#include <vector>

#include "IDistributedItem.h"
#include "Account.h"
#include "IBalanceStriker.h"


class Budget : public IDistributedItem, public IBalanceStriker
{
public:
    Budget();
    virtual ~Budget();
    
public:
    int AddAccount(t_Account_ptr pAccount);
    int CloseAccount(t_Account_ptr pAccount);
    
public:
    virtual int GetId(t_DistibutedId &refId);
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION);
    virtual t_money StrikeBalance(void);

private:
    typedef std::vector<t_Account_ptr> t_AccountColl;
    t_AccountColl m_aAccounts;
};