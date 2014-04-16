
#include "MemSaveSerializer.h"



void MemSaveSerializer::Serialize(int32_t&)
{
}


void MemSaveSerializer::Serialize(t_timestamp&)
{
}


void MemSaveSerializer::Serialize(std::wstring&)
{
}


void MemSaveSerializer::Serialize(std::string&)
{
}


void MemSaveSerializer::Serialize(t_money&)
{
}


ISerializer::SerializeMode MemSaveSerializer::GetMode(void)
{
    return SM_SAVER;
}


void MemSaveSerializer::Serialize(::google::protobuf::Message&)
{
}