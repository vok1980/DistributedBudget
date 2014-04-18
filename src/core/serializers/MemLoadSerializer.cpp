
#include "MemLoadSerializer.h"



MemLoadSerializer::MemLoadSerializer(std::istream *pStream) :
    m_pStream(pStream)
{
}


ISerializer::SerializeMode MemLoadSerializer::GetMode(void)
{
    return SM_LOADER;
}


void MemLoadSerializer::Serialize(::google::protobuf::Message &message, const t_DistibutedId &id)
{
    if (m_pStream)
        message.ParseFromIstream(m_pStream);
}


void MemLoadSerializer::SetStream(std::istream *pStream)
{
    m_pStream = pStream;
}
