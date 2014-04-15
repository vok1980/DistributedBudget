
#include "Budget.h"

#include <algorithm>
#include "SHA1EngineExt.h"

#include "SerializationHelpers.h"



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
    SHA1EngineExt engine(refId);

    std::for_each(m_aAccounts.begin(), m_aAccounts.end(),
    		[&engine](t_AccountColl::value_type &account)
    		{
    			t_DistibutedId accountId;
    			account.GetId(accountId);
    			engine.update(accountId);
    		}
    );

    return 0;
}


int Budget::Serialize(ISerializer &refSerializer, int32_t iVersion /*= LAST_SERIALIZE_VERSION*/)
{
    refSerializer.Serialize(iVersion);
    
    if (iVersion > LAST_SERIALIZE_VERSION)
        return 1;
    
    SerializationHelperColl(m_aAccounts, refSerializer, iVersion);
    
    return 0;
}


t_money Budget::StrikeBalance(void)
{
    t_money dResult = 0.0;
    
    std::for_each(m_aAccounts.begin(), m_aAccounts.end(),
                  [&dResult](t_AccountColl::value_type &account)
                  {
                      dResult += account.GetObject()->StrikeBalance();
                  }
    );
    
    return dResult;
}


int Budget::LoadFrom(const t_Buffer &protobuf)
{
    return -1;
}


int Budget::SaveTo(t_Buffer &protobuf)
{
    return -1;
}



