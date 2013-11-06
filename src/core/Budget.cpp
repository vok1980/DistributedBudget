
#include "Budget.h"



Budget::Budget()
{
}


Budget::~Budget()
{
}


int Budget::AddAccount(t_Account_ptr pAccount)
{
    m_aAccounts.push_back(pAccount);
    return 0;
}


int Budget::CloseAccount(t_Account_ptr pAccount)
{
    return -1;
}


int Budget::GetId(t_DistibutedId &refId)
{
    return -1;
}


int Budget::Serialize(ISerializer&)
{
    return -1;
}


t_money Budget::StrikeBalance(void)
{
    t_money dResult = 0.0;
    
    std::for_each(m_aAccounts.begin(), m_aAccounts.end(),
                  [&dResult](t_Account_ptr pAccount)
                  {
                      dResult += pAccount->StrikeBalance();
                  }
    );
    
    return dResult;
}


