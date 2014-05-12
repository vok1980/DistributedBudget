
#pragma once 

#include "Poco/SingletonHolder.h"


template <class T>
class Singleton
{
    friend class Poco::SingletonHolder<T>;
    
	Singleton(const Singleton&);
	void operator=(const Singleton&);
    
protected:
    Singleton();

public:
	static T& Instance()
	{
        static Poco::SingletonHolder<T> sh;
        return *sh.get();
	}
};
