
#include "MemLoadSerializer.h"



void MemLoadSerializer::Serialize(int32_t&)
{
}


void MemLoadSerializer::Serialize(t_timestamp&)
{
}


void MemLoadSerializer::Serialize(std::wstring&)
{
}


void MemLoadSerializer::Serialize(std::string&)
{
}


void MemLoadSerializer::Serialize(t_money&)
{
}


ISerializer::SerializeMode MemLoadSerializer::GetMode(void)
{
    return SM_LOADER;
}


void MemLoadSerializer::Serialize(::google::protobuf::Message&)
{
}

