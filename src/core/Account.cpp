
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
    
    t_DistibutedId head;
    m_pHeadTrunsuction->GetId(head);
    
    refSerializer.Serialize(head);
    
    
    return -1;
}


void Account::AddTransaction(t_Transaction_ptr pTransaction)
{
    m_pHeadTrunsuction = pTransaction->Embed(m_pHeadTrunsuction);
}


t_money Account::StrikeBalance(void)
{
	t_Transaction_ptr pTransaction = m_pHeadTrunsuction;
	t_money balance = 0.0;

	while (NULL != pTransaction.get())
	{
		balance += pTransaction->GetAmount();
		pTransaction = pTransaction->GetParent();
	}

	return balance;
}



