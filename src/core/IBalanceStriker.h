
#pragma once

#include "types.h"



class IBalanceStriker
{
public:
	virtual t_money StrikeBalance(void) = 0;
};

