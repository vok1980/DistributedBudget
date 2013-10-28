
#pragma once

#include "IDistributedItem.h"



class Transuction : public IDistributedItem
{
public:
    virtual int GetSha(std::string &strSha);
};
