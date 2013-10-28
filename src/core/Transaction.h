
#pragma once

#include "IDistributedItem.h"
#include "types.h"


class Transaction : public IDistributedItem
{
public:
    virtual int GetSha(t_sha &refSha);

private:
    t_timestamp m_timestamp;
    t_money m_amount;
    std::wstring m_strName;
    std::wstring m_strComment;
};


