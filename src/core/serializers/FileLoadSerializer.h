
#pragma once

#include "MemLoadSerializer.h"

#include "Poco/Path.h"


namespace core {

class FileLoadSerializer : public MemLoadSerializer
{
public:
    FileLoadSerializer(const Poco::Path &strPath);
    int Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id);
    
private:
    Poco::Path m_strPath;
};
    
};
