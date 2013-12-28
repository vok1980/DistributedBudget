
#pragma once

#include "IDistributedItem.h"
#include "IBalanceStriker.h"
#include "types.h"
#include "Transaction.h"
#include "TObjectHolder.h"
//#include "Account.pb.h"

namespace coremess
{
    class Account;
}



class Account : public IDistributedItem<coremess::Account>, public IBalanceStriker
{
public:
	Account();
	virtual ~Account();

public:
    virtual int GetId(t_DistibutedId &refId);
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION);
    
    void AddTransaction(t_Transaction_ptr pTransaction);
    t_money StrikeBalance(void);
    
    virtual int LoadFrom(const t_Buffer&);
    virtual int SaveTo(t_Buffer&);
    
private:
    std::wstring m_strName;
    std::wstring m_strDescription;
    
    TObjectHolder<Transaction> m_headTrunsuction;
};


typedef std::tr1::shared_ptr<Account> t_Account_ptr;
