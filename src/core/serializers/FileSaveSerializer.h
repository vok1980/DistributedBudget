
#pragma once

#include "MemSaveSerializer.h"

#include "Poco/Path.h"


class FileSaveSerializer : public MemSaveSerializer
{
public:
    FileSaveSerializer(const Poco::Path &path);
    
    virtual int Serialize(::google::protobuf::Message&, const t_DistibutedId &id);
    
private:
    Poco::Path m_path;
};
