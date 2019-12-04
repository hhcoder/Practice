#include <stdlib.h>
#include <stdio.h>

static unsigned Fib(const unsigned int n)
{
  if(0==n)
    return 0;
  if( 1==n || 2==n)
    return 1;

  return Fib(n-1)+Fib(n-2);
}

static int TestFib(const unsigned int n, const unsigned expected_n)
{
   return (expected_n==Fib(n));
}

#define TEST_FIB(_a_, _b_) \
  if( 1!=TestFib(_a_, _b_) ) \
  { \
    printf("Fail!\n"); \
    return -1; \
  }

//Fibonacci sequence is characterized by the fact that every number in it is the sum of the two preceding ones
// i.e., 1 1 2 3 5 8 13 21 34 
int main(int argc, char* argv[])
{

  TEST_FIB(0, 0);
  TEST_FIB(1, 1);
  TEST_FIB(2, 1);
  TEST_FIB(5, 5);
  TEST_FIB(10, 55);

  printf("Success!\n");
  return 0;
}

