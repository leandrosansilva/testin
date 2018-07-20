#pragma once

#ifdef TESTIN_ENABLED

#include <vector>
#include <functional>
#include <utility>
#include <iostream>
#include "3rd/snowhouse/snowhouse.h"

#define TESTIN_TOKENPASTE(x, y) x ## y
#define TESTIN_TOKENPASTE2(x, y) TESTIN_TOKENPASTE(x, y)

#define TESTIN_CASE(NAME, CODE) static auto TESTIN_TOKENPASTE2(___testin_case___, __LINE__) = Testin::makeCase(__testin_test_suit, NAME, CODE)

#define TESTIN_MAKE_TESTABLE(A) extern void testin_make_testable_##A(); testin_make_testable_##A()

#define TESTIN_RUN() Testin::run()

#define TESTIN_SUITE(A) \
  using namespace snowhouse; \
  static Testin::TestSuite __testin_test_suit; \
  void testin_make_testable_##A() \
  { \
    __testin_test_suit._name = #A; \
    Testin::registerSuite(__testin_test_suit);\
  }

namespace Testin {
  struct Tester;

  using callback_type = void();

  struct TestSuite
  {
    const char* _name{nullptr};

    std::vector<std::pair<const char*, std::function<callback_type>>> _testCases;

    void run();

    void addTestCase(const char*, Testin::callback_type);
  };

  Tester& instance();

  struct Tester
  {
    std::vector<TestSuite*> _suites;

    void run();
  };

  struct Case
  {
    explicit Case(TestSuite&, const char*, callback_type);
  };

  Case makeCase(TestSuite&, const char*, callback_type);

  void run();

  void registerSuite(TestSuite&);
}

#else

#define TESTIN_CASE(NAME, CODE)

#define TESTIN_MAKE_TESTABLE(A)

#define TESTIN_SUITE(A)

#define TESTIN_RUN()

#endif


