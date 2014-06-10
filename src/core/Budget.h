
#pragma once

#include <vector>

#include "DistributedItem.h"
#include "Account.h"
#include "IBalanceStriker.h"
#include "TObjectHolder.h"
#include "Budget.pb.h"


namespace coremess
{
    class Budget;
}


namespace core {

class Budget : public DistributedItem<coremess::Budget>, public IBalanceStriker
{
public:
    Budget();
    virtual ~Budget();
    
public:
    int AddAccount(t_Account_ptr pAccount);
    int CloseAccount(t_Account_ptr pAccount);
    
public:
    virtual int GetId(t_DistibutedId &refId);
    virtual t_money StrikeBalance(void);
    
    virtual int LoadFrom(const t_Buffer&);
    virtual int SaveTo(t_Buffer&);

private:
    typedef std::vector< TObjectHolder<Account> > t_AccountColl;
    t_AccountColl m_aAccounts;
};

typedef std_shared::shared_ptr<Budget> t_Budget_ptr;

};
