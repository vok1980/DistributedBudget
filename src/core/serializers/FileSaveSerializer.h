
#pragma once

#include "MemSaveSerializer.h"


class FileSaveSerializer : public MemSaveSerializer
{
public:
    FileSaveSerializer(const std::string &strPath);
    
    virtual void Serialize(::google::protobuf::Message&, const t_DistibutedId &id);
    
private:
    std::string m_strPath;
};
