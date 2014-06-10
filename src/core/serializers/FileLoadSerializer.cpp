
#include "FileLoadSerializer.h"

#include <fstream>
#include <stdexcept>


namespace core {

FileLoadSerializer::FileLoadSerializer(const Poco::Path &path) :
    MemLoadSerializer(NULL),
    m_strPath(path)
{
    
}


int FileLoadSerializer::Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id) throw (std::runtime_error)
{
    assert(!id.empty());
    
    if (!id.empty())
    {
        Poco::Path pathFile(m_strPath);
        pathFile.append(id);
    
        std::ifstream input( pathFile.toString().c_str() );
        
        if (!input.is_open())
            throw std::runtime_error( std::string("FileLoadSerializer::Serialize: file not opend: ") + pathFile.toString() );
    
        SetStream(&input);
        return MemLoadSerializer::Serialize(protobuf, id);
    }
    
    return 3;
}

};
