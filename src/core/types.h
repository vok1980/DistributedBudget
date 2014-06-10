
#pragma once

#ifdef __GXX_EXPERIMENTAL_CXX0X__
    #include <tr1/memory>
    namespace std_shared = std::tr1;
#else
    #include <memory>
    namespace std_shared = std;
#endif	//__GXX_EXPERIMENTAL_CXX0X__

#include <Poco/Timestamp.h>

#ifdef WIN32
#define int32_t _int32  
#endif



typedef Poco::Timestamp t_timestamp;
typedef float t_money;
typedef std::string t_DistibutedId;
