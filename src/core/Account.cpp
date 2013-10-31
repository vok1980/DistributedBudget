
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


void Account::AddTransaction(t_Transaction_ptr pTransaction)
{
	pTransaction->SetParent(m_pHeadTrunsuction);
	m_pHeadTrunsuction = pTransaction;
}


t_money Account::StrikeBalance(void)
{
	t_Transaction_ptr pTransaction = m_pHeadTrunsuction;
	t_money balance = 0;

	while (NULL != pTransaction.get())
	{
		balance += pTransaction->GetAmount();
		pTransaction = pTransaction->GetParent();
	}

	return balance;
}



