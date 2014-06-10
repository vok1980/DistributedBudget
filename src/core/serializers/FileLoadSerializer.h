
#pragma once

#include "MemLoadSerializer.h"

#include "Poco/Path.h"
#include <stdexcept>


namespace core {

class FileLoadSerializer : public MemLoadSerializer
{
public:
    FileLoadSerializer(const Poco::Path &strPath);
    int Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id) throw (std::runtime_error);
    
private:
    Poco::Path m_strPath;
};
    
};
