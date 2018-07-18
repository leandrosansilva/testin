#include "testin.h"

#ifdef TESTIN_ENABLED

#include <mutex>
#include <iostream>

Testin::Tester& Testin::instance()
{
	static std::once_flag flag;
	static Tester* instance = nullptr;

	std::call_once(flag, []{
		instance = new Testin::Tester;
	});

	return *instance;
}

#endif
