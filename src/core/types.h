
#pragma once

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <tr1/memory>
#define t_shared_ptr std::tr1::shared_ptr
#define t_weak_ptr std::tr1::weak_ptr
#else
#include <memory>
#define t_shared_ptr std::shared_ptr
#define t_weak_ptr std::weak_ptr
#endif	//__GXX_EXPERIMENTAL_CXX0X__

#include <Poco/Timestamp.h>

#ifdef WIN32
#define int32_t _int32  
#endif



typedef Poco::Timestamp t_timestamp;
typedef float t_money;
typedef std::string t_DistibutedId;
