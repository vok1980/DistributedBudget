
#pragma once

#include <list>
#include "IDistributedItem.h"
#include "Account.h"


class Budget : public IDistributedItem
{
public:
    Budget();
    virtual ~Budget();
    
public:
    int AddAccount(t_Account_ptr pAccount);
    int CloseAccount(t_Account_ptr pAccount);

private:
    typedef std::list<t_Account_ptr> t_AccountColl;
    t_AccountColl m_aAccounts;
};