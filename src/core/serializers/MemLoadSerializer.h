
#pragma once

#include "ISerializer.h"

#include <istream>


namespace core {
    
class MemLoadSerializer : public ISerializer
{
public:
    MemLoadSerializer(std::istream *pStream);
    
public:
    virtual SerializeMode GetMode(void);
    virtual int Serialize(::google::protobuf::Message&, const t_DistibutedId &id);
    
    void SetStream(std::istream *pStream);
    
private:
    std::istream *m_pStream;
};

};
