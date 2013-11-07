
#pragma once


typedef float t_money;


class IBalanceStriker
{
public:
	virtual t_money StrikeBalance(void) = 0;
};

