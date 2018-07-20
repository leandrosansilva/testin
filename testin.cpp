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
  for (const auto& suite: _suites) {
    std::cout << "Test Suite: \"" << suite->_name << "\"\n";
    suite->run();
  }
}

void TestSuite::run()
{
  for (auto& testCase: _testCases) {
    std::cout << "Running Test Case: \"" << testCase.first << "\"\n";
    testCase.second();
  }
}

void TestSuite::addTestCase(const char* name, callback_type function)
{
  _testCases.emplace_back(name, function);
}

Case::Case(TestSuite& suite, const char* name, callback_type function)
{
  suite.addTestCase(name, function);
}

Case makeCase(TestSuite& suite, const char* name, callback_type function)
{
  return Case(suite, name, function);
}

void run()
{
  instance().run();
}

void registerSuite(TestSuite& suite)
{
  instance()._suites.push_back(&suite);
}

}

#endif
