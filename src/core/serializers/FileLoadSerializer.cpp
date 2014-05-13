
#include "FileLoadSerializer.h"

#include <fstream>



FileLoadSerializer::FileLoadSerializer(const Poco::Path &path) :
    MemLoadSerializer(NULL),
    m_strPath(path)
{
    
}


int FileLoadSerializer::Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id)
{
    assert(!id.empty());
    
    if (!id.empty())
    {
        Poco::Path pathFile(m_strPath);
        pathFile.append(id);
    
        std::ifstream input( pathFile.toString().c_str() );
        assert(input.is_open());
    
        SetStream(&input);
        return MemLoadSerializer::Serialize(protobuf, id);
    }
    
    return 3;
}

