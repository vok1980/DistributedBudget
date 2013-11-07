
#include "Account.h"

#include "Transaction.h"




Account::Account()
{}


Account::~Account()
{}


int Account::GetId(t_DistibutedId &refId)
{
    return 0;
}


int Account::Serialize(ISerializer &refSerializer, int32_t iVersion /*= LAST_SERIALIZE_VERSION*/)
{
    refSerializer.Serialize(iVersion);
    
    if (iVersion > LAST_SERIALIZE_VERSION)
        return 1;
    
    refSerializer.Serialize(m_strName);
    refSerializer.Serialize(m_strDescription);
    
    m_headTrunsuction.Serialize(refSerializer);
    
    return 0;
}


void Account::AddTransaction(t_Transaction_ptr pTransaction)
{
    m_headTrunsuction = pTransaction->Embed(m_headTrunsuction.GetObject());
}


t_money Account::StrikeBalance(void)
{
	t_Transaction_ptr pTransaction = m_headTrunsuction.GetObject();
	t_money balance = 0.0;

	while (NULL != pTransaction.get())
	{
		balance += pTransaction->GetAmount();
		pTransaction = pTransaction->GetParent();
	}

	return balance;
}



