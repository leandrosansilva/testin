#include "example.h"
#include "testin.h"

int Example::add(int f, int s) const
{
  return f + s;
}

TESTIN_CASE("0 + 0 is 0", []{
  const auto e = Example{};
  assert(e.add(0, 0) == 0);
});

TESTIN_CASE("0 + 1 is 1", []{
  const auto e = Example{};
  assert(e.add(0, 1) == 1);
});

TESTIN_CASE("1 + 1 is 2", []{
  const auto e = Example{};
  assert(e.add(1, 1) == 2);
});

TESTIN_CASE("2 + 1 is 3", []{
  const auto e = Example{};
  assert(e.add(2, 1) == 3);
});
