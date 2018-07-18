#pragma once

#ifdef TESTIN_ENABLED

// TODO: use https://github.com/banditcpp/snowhouse
#include <assert.h>

#include <vector>
#include <functional>
#include <utility>
#include <iostream>

#define TESTIN_TOKENPASTE(x, y) x ## y
#define TESTIN_TOKENPASTE2(x, y) TESTIN_TOKENPASTE(x, y)
#define TESTIN_CASE(NAME, CODE) static auto TESTIN_TOKENPASTE2(___testin_case___, __LINE__) = Testin::makeCase(NAME, CODE)

namespace Testin {
  struct Tester;

  Tester& instance();

  using callback_type = void();

  struct Tester
  {
    std::vector<std::pair<const char*, std::function<callback_type>>> _testCases;

    inline void addTestCase(const char* name, callback_type function)
    {
      _testCases.emplace_back(name, function);
    }

    inline void run()
    {
      for (auto& testCase: _testCases) {
        std::cout << "Running Test Case: \"" << testCase.first << "\"\n";
        testCase.second();
      }
    }
  };

  struct Case
  {
    inline explicit Case(const char* name, callback_type function)
    {
      instance().addTestCase(name, function);
    }
  };

  inline Case makeCase(const char* name, callback_type function)
  {
    return Case(name, function);
  }

  inline void run()
  {
    instance().run();
  }
}

#else

#define TESTIN_CASE(NAME, CODE)

namespace Testin {
  inline void run()
  {
  }
}

#endif


