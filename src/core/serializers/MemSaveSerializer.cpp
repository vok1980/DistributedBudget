
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


int MemSaveSerializer::Serialize(::google::protobuf::Message &message, const t_DistibutedId &id)
{
    if (!m_pStream)
        return 1;
    
    return message.SerializeToOstream(m_pStream) ? 0 : 7;
}


void MemSaveSerializer::SetStream(std::ostream *pStream)
{
    m_pStream = pStream;
}

