
#pragma once

#include <set>
#include <string>

#include "types.h"
#include "IBalanceStriker.h"


class ISerializer
{
public:
	virtual void Serialize(int32_t&) = 0;
	virtual void Serialize(t_timestamp&) = 0;
	virtual void Serialize(std::wstring&) = 0;
    virtual void Serialize(std::string&) = 0;
	virtual void Serialize(std::set<std::wstring>&) = 0;
	virtual void Serialize(t_money&) = 0;
};
