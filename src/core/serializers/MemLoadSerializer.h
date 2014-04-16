
#pragma once

#include "ISerializer.h"

#include <istream>

class MemLoadSerializer : public ISerializer
{
public:
    MemLoadSerializer(std::istream *pStream);
    
public:
    virtual SerializeMode GetMode(void);
    virtual void Serialize(::google::protobuf::Message&);
    
private:
    std::istream *m_pStream;
};

