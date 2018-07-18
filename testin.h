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
    void addTestCase(const char*, Testin::callback_type);

    void run();
  };

  struct Case
  {
    explicit Case(const char*, callback_type);
  };

  Case makeCase(const char*, callback_type);

  void run();
}

#else

#define TESTIN_CASE(NAME, CODE)

namespace Testin {
  inline void run()
  {
  }
}

#endif


