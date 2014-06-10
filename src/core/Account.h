
#pragma once

#include "DistributedItem.h"
#include "IBalanceStriker.h"
#include "types.h"
#include "Transaction.h"
#include "TObjectHolder.h"
#include "Account.pb.h"


namespace coremess
{
    class Account;
}

namespace core {

class Account : public DistributedItem<coremess::Account>, public IBalanceStriker
{
public:
	Account();
	virtual ~Account();

public:
    virtual int GetId(t_DistibutedId &refId);
    
    void AddTransaction(t_Transaction_ptr pTransaction);
    t_money StrikeBalance(void);

    void SetName(const std::wstring &_name);
    std::wstring GetName() const;

    void SetDescription(const std::wstring &_description);
    std::wstring GetDescription() const;
    
    virtual int LoadFrom(const t_Buffer&);
    virtual int SaveTo(t_Buffer&);
    
private:
    std::wstring m_strName;
    std::wstring m_strDescription;
    
    TObjectHolder<Transaction> m_headTrunsuction;
};


typedef std_shared::shared_ptr<Account> t_Account_ptr;

};

