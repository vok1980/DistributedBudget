
#pragma once

#include <vector>

#include "IDistributedItem.h"
#include "Account.h"
#include "IBalanceStriker.h"
#include "TObjectHolder.h"
//#include "Budget.pb.h"


namespace coremess
{
    class Budget;
}


class Budget : public IDistributedItem<coremess::Budget>, public IBalanceStriker
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
    
    virtual int LoadFrom(const t_Buffer&);
    virtual int SaveTo(t_Buffer&);

private:
    typedef std::vector< TObjectHolder<Account> > t_AccountColl;
    t_AccountColl m_aAccounts;
};

