
#pragma once

#include "MemSaveSerializer.h"

#include "Poco/Path.h"
#include <stdexcept>


namespace core {

class FileSaveSerializer : public MemSaveSerializer
{
public:
    FileSaveSerializer(const Poco::Path &path);
    
    virtual int Serialize(::google::protobuf::Message&, const t_DistibutedId &id) throw (std::runtime_error);
    
private:
    Poco::Path m_path;
};

};
