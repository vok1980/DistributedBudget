
#pragma once

#include <vector>

#include "TObjectHolder.h"
#include "IDistributedItem.h"
#include "types.h"
#include "Category.h"



class Transaction : public IDistributedItem, public std::tr1::enable_shared_from_this<Transaction>
{
public:
	Transaction(t_timestamp tsEvent, t_money amount);
	virtual ~Transaction();

public:
    virtual int GetId(t_DistibutedId &refId);
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION);

    virtual t_money GetAmount(void);
    t_Transaction_ptr GetParent(void);
    void SetParent(t_Transaction_ptr pParent);
    virtual t_Transaction_ptr Embed(t_Transaction_ptr pOldHead);

private:
    t_timestamp m_tsEvent;
    t_money m_amount;
    std::wstring m_strName;
    std::wstring m_strComment;
    typedef std::vector< TObjectHolder<Category> > t_CategoryColl;
    t_CategoryColl m_aCategory;

private:
    TObjectHolder<Transaction> m_parentTransaction;
};


