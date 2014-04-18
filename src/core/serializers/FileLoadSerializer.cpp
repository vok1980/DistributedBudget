
#include "FileLoadSerializer.h"

#include <fstream>



FileLoadSerializer::FileLoadSerializer(const std::string &strPath) :
    MemLoadSerializer(NULL),
    m_strPath(strPath)
{
    
}


void FileLoadSerializer::Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id)
{
    assert(!id.empty());
    
    if (!id.empty())
    {
        std::string strFileName = id;
        std::string strFullPath = m_strPath + "/" + strFileName;
    
        std::ifstream input( strFullPath.c_str() );
    
        SetStream(&input);
        MemLoadSerializer::Serialize(protobuf, id);
    }
}

