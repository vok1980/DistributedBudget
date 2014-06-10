
#include "FileSaveSerializer.h"

#include <fstream>



namespace core {

FileSaveSerializer::FileSaveSerializer(const Poco::Path &path) :
    MemSaveSerializer(NULL),
    m_path(path)
{
}


int FileSaveSerializer::Serialize(::google::protobuf::Message &protobuf, const t_DistibutedId &id) throw (std::runtime_error)
{
    Poco::Path pathFile(m_path);
    pathFile.append(id);
    
    std::ofstream out;
    out.open( pathFile.toString().c_str(), std::ios_base::out | std::ios_base::binary );

    if (!out.is_open())
    	throw std::runtime_error(std::string("FileSaveSerializer::Serialize: file not opend: ") + pathFile.toString());

    SetStream(&out);
    return MemSaveSerializer::Serialize(protobuf, id);
    out.close();
    
    return 0;
}

};
