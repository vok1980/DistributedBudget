
#include "MemSaveSerializer.h"

#include <sstream>


MemSaveSerializer::MemSaveSerializer(std::ostream* pStream) :
    m_pStream(pStream)
{
}


ISerializer::SerializeMode MemSaveSerializer::GetMode(void)
{
    return SM_SAVER;
}


void MemSaveSerializer::Serialize(::google::protobuf::Message &message, const t_DistibutedId &id)
{
    if (m_pStream)
        message.SerializeToOstream(m_pStream);
}


void MemSaveSerializer::SetStream(std::ostream *pStream)
{
    m_pStream = pStream;
}

