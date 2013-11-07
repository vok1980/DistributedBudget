//
//  Categiry.h
//  DistributedBudget
//
//  Created by Vyacheslav Koscheev on 10/30/13.
//
//

#pragma once

#include <tr1/memory>
#include "IDistributedItem.h"




class Category : public IDistributedItem
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
};


typedef std::tr1::shared_ptr<Category> t_Category_ptr;

