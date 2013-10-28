
#pragma once

#include <string>


class IDistributedItem
{
public:
	virtual ~IDistributedItem();
    virtual int GetSha(std::string &) = 0;
};
