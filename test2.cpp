#include "testin.h"

TESTIN_SUITE(tests2)

TESTIN_CASE("Multiply something", []{
  AssertThat(2 * 3, Is().EqualTo(6));
});
