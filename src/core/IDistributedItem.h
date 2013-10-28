
#pragma once

#include <string>


class IDistributedItem
{
public:
    virtual int GetSha(std::string &) = 0;
};
