
#pragma once

#include <Poco/SHA1Engine.h>
#include <Poco/Timestamp.h>

#include "types.h"


class SHA1EngineExt : protected Poco::SHA1Engine
{
public:
	SHA1EngineExt(t_DistibutedId &refId);
	virtual ~SHA1EngineExt();

public:
	void update(const std::wstring& data);
	void update(const std::string& data);
	void update(const Poco::Timestamp &data);
	void update(const t_money &data);

private:
	void GetSha1(t_DistibutedId &refId);

private:
	t_DistibutedId &m_refId;
};

