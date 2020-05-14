#include "foobar.h"

int baz; // definição da variável

int foo(long arg)
{
  baz += arg;
  return baz + bar() - 2; // só posso chamar bar() aqui porque a declarei antes
}

int bar(void)
{
  return 4;
}