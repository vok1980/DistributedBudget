
#pragma once

#include <list>

#include "IDistributedItem.h"
#include "types.h"
#include "Category.h"


class Transaction : public IDistributedItem
{
public:
	Transaction();
	virtual ~Transaction();

public:
    virtual int GetId(t_DistibutedId &refId);
    virtual int Serialize(ISerializer&);

private:
    t_timestamp m_tsEvent;
    t_money m_amount;
    std::wstring m_strName;
    std::wstring m_strComment;
    std::list<t_Category_ptr> m_aCategory;
    t_Transaction_ptr m_pParentTransaction;
};


