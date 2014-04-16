
#include "MemLoadSerializer.h"



MemLoadSerializer::MemLoadSerializer(std::istream *pStream) :
    m_pStream(pStream)
{
}


ISerializer::SerializeMode MemLoadSerializer::GetMode(void)
{
    return SM_LOADER;
}


void MemLoadSerializer::Serialize(::google::protobuf::Message &message)
{
    message.ParseFromIstream(m_pStream);
}

