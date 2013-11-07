
#pragma once


#include <tr1/memory>

#include <Poco/Timestamp.h>




class Transaction;
typedef std::tr1::shared_ptr<Transaction> t_Transaction_ptr;

typedef Poco::Timestamp t_timestamp;
