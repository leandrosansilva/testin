#include "testin.h"

TESTIN_SUITE(tests2)

TESTIN_CASE("Multiply something", []{
  assert(2 * 3 == 6);
});
