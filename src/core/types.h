
#pragma once


#include <tr1/memory>


class Transaction;
typedef std::tr1::shared_ptr<Transaction> t_Transaction_ptr;

typedef std::string t_sha;
typedef int t_timestamp;
typedef float t_money;
