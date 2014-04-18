
#pragma once

#include "MemLoadSerializer.h"


class FileLoadSerializer : public MemLoadSerializer
{
    FileLoadSerializer(const std::string &strPath);
    void Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id);
    
private:
    std::string m_strPath;
};
