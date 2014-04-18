
#pragma once

#include "ISerializer.h"

class MemSaveSerializer : public ISerializer
{
public:
    MemSaveSerializer(std::ostream* pStream);
    
public:
    virtual SerializeMode GetMode(void);
    virtual void Serialize(::google::protobuf::Message&, const t_DistibutedId &id);
    void SetStream(std::ostream *pStream);
    
private:
    std::ostream *m_pStream;
};

