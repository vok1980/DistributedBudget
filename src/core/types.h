
#pragma once

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <tr1/memory>
#define t_shared_ptr std::tr1::shared_ptr
#else
#include <memory>
#define t_shared_ptr std::shared_ptr
#endif	//__GXX_EXPERIMENTAL_CXX0X__

#include <Poco/Timestamp.h>

#ifdef WIN32
#define int32_t _int32  
#endif


class Transaction;
typedef t_shared_ptr<Transaction> t_Transaction_ptr;

typedef Poco::Timestamp t_timestamp;
typedef float t_money;
typedef std::string t_DistibutedId;
