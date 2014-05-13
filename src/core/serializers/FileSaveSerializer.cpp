
#include "FileSaveSerializer.h"

#include <fstream>



FileSaveSerializer::FileSaveSerializer(const Poco::Path &path) :
    MemSaveSerializer(NULL),
    m_path(path)
{
}


int FileSaveSerializer::Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id)
{
    Poco::Path pathFile(m_path);
    pathFile.append(id);
    
    std::ofstream out;
    out.open( pathFile.toString().c_str(), std::ios_base::out | std::ios_base::binary );
    assert(out.is_open());

    SetStream(&out);
    return MemSaveSerializer::Serialize(protobuf, id);
    out.close();
    
    return 0;
}

