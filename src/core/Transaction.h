
#pragma once

#include "IDistributedItem.h"



class Transaction : public IDistributedItem
{
public:
    virtual int GetSha(std::string &strSha);
};
