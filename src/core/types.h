
#pragma once

#include <memory>

#include <Poco/Timestamp.h>

#ifdef WIN32
#define int32_t _int32  
#endif


class Transaction;
typedef std::tr1::shared_ptr<Transaction> t_Transaction_ptr;

typedef Poco::Timestamp t_timestamp;
typedef float t_money;
typedef std::string t_DistibutedId;
