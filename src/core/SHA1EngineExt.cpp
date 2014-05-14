
#include "SHA1EngineExt.h"
#include <Poco/Timestamp.h>


namespace core {


SHA1EngineExt::SHA1EngineExt(t_DistibutedId &refId) :
	m_refId(refId)
{
}


SHA1EngineExt::~SHA1EngineExt()
{
	GetSha1(m_refId);
}


void SHA1EngineExt::update(const std::wstring& data)
{
	SHA1Engine::update((void*)data.data(), data.size() * sizeof(std::wstring::value_type));
}


void SHA1EngineExt::update(const std::string& data)
{
	SHA1Engine::update(data);
}


void SHA1EngineExt::update(const Poco::Timestamp &data)
{
	Poco::Timestamp::TimeVal val = data.epochMicroseconds();
	SHA1Engine::update(&val, sizeof(val));
}


void SHA1EngineExt::update(const t_money &data)
{
	SHA1Engine::update(&data, sizeof(data));
}


void SHA1EngineExt::GetSha1(t_DistibutedId &refId)
{
    const Poco::DigestEngine::Digest &digest = SHA1Engine::digest();
    refId = Poco::DigestEngine::digestToHex(digest);
}

};

