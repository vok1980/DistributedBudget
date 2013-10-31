
#pragma once

#include <set>

#include "IDistributedItem.h"
#include "types.h"


class Transaction : public IDistributedItem
{
public:
	Transaction();
	virtual ~Transaction();

public:
    virtual int GetId(t_id &refId);
    virtual int Serialize(ISerializer&);

private:
    t_timestamp m_tsEvent;
    t_money m_amount;
    std::wstring m_strName;
    std::wstring m_strComment;
    std::set<std::wstring> m_aCategoryColl;
};


