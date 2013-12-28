//
//  Categiry.h
//  DistributedBudget
//
//  Created by Vyacheslav Koscheev on 10/30/13.
//
//

#pragma once

#include "IDistributedItem.h"
#include "types.h"
//#include "Category.pb.h"

namespace coremess
{
    class Category;
}


class Category : public IDistributedItem<coremess::Category>
{
public:
    Category();
    virtual ~Category();
    
public:
    virtual int GetId(t_DistibutedId &refId);
    virtual int Serialize(ISerializer&, int32_t iVersion = LAST_SERIALIZE_VERSION);
    
private:
    std::wstring m_strName;
    std::wstring m_strDescription;
    t_timestamp m_tsModification;
};


typedef std::tr1::shared_ptr<Category> t_Category_ptr;

