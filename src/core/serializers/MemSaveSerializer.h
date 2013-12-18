
#pragma once

#include "ISerializer.h"

class MemSaveSerializer : public ISerializer
{
	virtual void Serialize(int32_t&);
	virtual void Serialize(t_timestamp&);
	virtual void Serialize(std::wstring&);
    virtual void Serialize(std::string&);
	virtual void Serialize(t_money&);
};

