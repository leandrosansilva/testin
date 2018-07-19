#include "example.h"
#include "testin.h"

TESTIN_SUITE(examples)

namespace {
  int super_add_function(int f, int s)
  {
    return f + s;
  }
}

int Example::add(int f, int s) const
{
  return super_add_function(f, s);
}

TESTIN_CASE("0 + 0 is 0", []{
  assert(super_add_function(0, 0) == 0);
});

TESTIN_CASE("0 + 1 is 1", []{
  assert(super_add_function(0, 1) == 1);
});

TESTIN_CASE("1 + 1 is 2", []{
  assert(super_add_function(1, 1) == 2);
});

TESTIN_CASE("2 + 1 is 3", []{
  assert(super_add_function(2, 1) == 3);
});
