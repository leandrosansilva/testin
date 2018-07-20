#include "example.h"
#include "testin.h"

int main(int, char**)
{
  TESTIN_MAKE_TESTABLE(examples);
  TESTIN_MAKE_TESTABLE(tests2);
  TESTIN_RUN();

  return 0;
}
