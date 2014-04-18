
#include "FileSaveSerializer.h"

#include <fstream>



FileSaveSerializer::FileSaveSerializer(const std::string &strPath) :
    MemSaveSerializer(NULL)
{
}


void FileSaveSerializer::Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id)
{
    std::string strFileName = id;
    std::string strFullPath = m_strPath + "/" + strFileName;
    
    std::ofstream out( strFullPath.c_str() );
    
    SetStream(&out);
    MemSaveSerializer::Serialize(protobuf, id);
}

