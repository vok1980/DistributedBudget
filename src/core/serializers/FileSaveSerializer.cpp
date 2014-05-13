
#include "FileSaveSerializer.h"

#include <fstream>



FileSaveSerializer::FileSaveSerializer(const std::string &strPath) :
    MemSaveSerializer(NULL),
    m_strPath(strPath)
{
}


void FileSaveSerializer::Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id)
{
    std::string strFileName = id;
    std::string strFullPath = m_strPath + "/" + strFileName;
    
    std::ofstream out;
    out.open( strFullPath.c_str(), std::ios_base::out | std::ios_base::binary );
    assert(out.is_open());

    SetStream(&out);
    MemSaveSerializer::Serialize(protobuf, id);
    out.close();
}

