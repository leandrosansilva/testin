#include "testin.h"

#ifdef TESTIN_ENABLED

#include <mutex>
#include <iostream>

namespace Testin {

Tester& instance()
{
  static std::once_flag flag;
  static Tester* instance = nullptr;

  std::call_once(flag, []{
    instance = new Tester;
  });

  return *instance;
}

void Tester::run()
{
	for (auto& testCase: _testCases) {
		std::cout << "Running Test Case: \"" << testCase.first << "\"\n";
		testCase.second();
	}
}

void Tester::addTestCase(const char* name, callback_type function)
{
  _testCases.emplace_back(name, function);
}

Case::Case(const char* name, callback_type function)
{
  instance().addTestCase(name, function);
}

Case makeCase(const char* name, callback_type function)
{
  return Case(name, function);
}

void run()
{
  instance().run();
}


}

#endif
