
#include "MemLoadSerializer.h"


namespace core {

MemLoadSerializer::MemLoadSerializer(std::istream *pStream) :
    m_pStream(pStream)
{
}


ISerializer::SerializeMode MemLoadSerializer::GetMode(void)
{
    return SM_LOADER;
}


int MemLoadSerializer::Serialize(::google::protobuf::Message &message, const t_DistibutedId &id)
{
    if (!m_pStream)
        return 1;
    
    return message.ParseFromIstream(m_pStream) ? 0 : 6;
}


void MemLoadSerializer::SetStream(std::istream *pStream)
{
    m_pStream = pStream;
}

};
