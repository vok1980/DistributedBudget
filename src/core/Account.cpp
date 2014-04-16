
#include <cstdlib>


#include "Account.h"

#include "Transaction.h"

#include "SHA1EngineExt.h"

#include "Sha.pb.h"
#include "Account.pb.h"



Account::Account()
{}


Account::~Account()
{
}


int Account::GetId(t_DistibutedId &refId)
{
    SHA1EngineExt engine(refId);

    engine.update(m_strName);
    engine.update(m_strDescription);

    t_DistibutedId tranactionId;
    m_headTrunsuction.GetId(tranactionId);
    engine.update(tranactionId);

    return 0;
}




void Account::SetName(const std::wstring &_name)
{
    m_strName = _name;
}


std::wstring Account::GetName() const
{
    return m_strName;
}


void Account::SetDescription(const std::wstring &_description)
{
    m_strDescription = _description;
}


std::wstring Account::GetDescription() const
{
    return m_strDescription;
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


#define MAX_W_CHARS 1024
#define MAX_MB_CHARS (2 * MAX_W_CHARS)


int Account::LoadFrom(const t_Buffer& protobuf)
{
    m_headTrunsuction.SetObject(protobuf.head());

    wchar_t buffer[MAX_W_CHARS];

    mbstowcs(buffer, protobuf.name().c_str(), MAX_W_CHARS);
    m_strName = buffer;
    mbstowcs(buffer, protobuf.description().c_str(), MAX_W_CHARS);
    m_strDescription = buffer;
    
    return 0;
}


int Account::SaveTo(t_Buffer &protobuf)
{
    t_DistibutedId id;

    if (0 == m_headTrunsuction.GetId(id))
    {
        protobuf.set_head(id);
    }
    
    char buffer[MAX_MB_CHARS];
    
    wcstombs(buffer, m_strName.c_str(), MAX_MB_CHARS);
    protobuf.set_name(buffer);

    wcstombs(buffer, m_strDescription.c_str(), MAX_MB_CHARS);
    protobuf.set_description(buffer);
    
    return 0;
}



