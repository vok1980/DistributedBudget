//
//  Categiry.h
//  DistributedBudget
//
//  Created by Vyacheslav Koscheev on 10/30/13.
//
//

#pragma once

#include "DistributedItems/DistributedItem.h"
#include "types.h"
#include "TObjectHolder.h"
#include "Category.pb.h"


namespace coremess
{
    class Category;
}


namespace core {

class Category : public DistributedItem<coremess::Category>
{
public:
    typedef TObjectHolder<Category> t_Holder;
    
    Category();
    virtual ~Category();
    
public:
    virtual int GetId(t_DistibutedId &refId);
    
    void SetName(const std::wstring &_name);
    std::wstring GetName() const;
    
    void SetDescription(const std::wstring &_description);
    std::wstring GetDescription() const;
    
    virtual int LoadFrom(const t_Buffer&);
    virtual int SaveTo(t_Buffer&);
    
private:
    std::wstring m_strName;
    std::wstring m_strDescription;
    t_timestamp m_tsModification;
};


typedef std::shared_ptr<Category> t_Category_ptr;

};
