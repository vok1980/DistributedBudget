
#include "Budget.h"

#include <algorithm>



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


int Budget::Serialize(ISerializer &refSerializer, int32_t iVersion /*= LAST_SERIALIZE_VERSION*/)
{
    refSerializer.Serialize(iVersion);
    
    if (iVersion > LAST_SERIALIZE_VERSION)
        return 1;
    
    int32_t iAccountsSize = m_aAccounts.size();
    refSerializer.Serialize(iAccountsSize);
    m_aAccounts.resize(iAccountsSize);
    
    for (int lc = 0; lc < iAccountsSize; ++lc)
    {
        if ( !m_aAccounts.at(lc) )
            m_aAccounts[lc] = t_Account_ptr(new Account());
        
        m_aAccounts.at(lc)->Serialize(refSerializer);
    }
    
    return 0;
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


