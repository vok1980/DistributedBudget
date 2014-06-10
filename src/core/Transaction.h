
#pragma once

#include <vector>

#include "TObjectHolder.h"
#include "DistributedItems/DistributedItem.h"
#include "types.h"
#include "Category.h"
#include "Transaction.pb.h"

namespace coremess
{
    class Transaction;
}


namespace core {
    
    class Transaction;
    typedef std_shared::shared_ptr<Transaction> t_Transaction_ptr;
    

class Transaction : public DistributedItem<coremess::Transaction>, public std_shared::enable_shared_from_this<Transaction>
{
public:
    Transaction();
	Transaction(t_timestamp tsEvent, t_money amount);
	virtual ~Transaction();

public:
    virtual int GetId(t_DistibutedId &refId);

    virtual std::wstring GetName(void);
    virtual void SetName(const std::wstring&);
    
    virtual std::wstring GetComment(void);
    virtual void SetComment(const std::wstring&);
    
    virtual t_money GetAmount(void);
    virtual t_timestamp GetTimestamp(void);
    t_Transaction_ptr GetParent(void);
    void SetParent(t_Transaction_ptr pParent);
    virtual t_Transaction_ptr Embed(t_Transaction_ptr pOldHead);

    void AddCategory(t_DistibutedId refCatId);
    
    virtual int LoadFrom(const t_Buffer&);
    virtual int SaveTo(t_Buffer&);

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
    

};

