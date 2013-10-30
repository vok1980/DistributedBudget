
#pragma once

#include <vector>
#include "IDistributedItem.h"
#include "Account.h"


class Budget : public IDistributedItem
{
public:
    Budget();
    virtual ~Budget();
    
public:
    t_Account_ptr AddAccount(const std::wstring &strName, const std::wstring &strDescription);
    int CloseAccount(t_Account_ptr pAccount);

private:
    typedef std::vector<t_Account_ptr> t_AccountColl;
};