#include <stdio.h>


int main()
{
  int precision = 8;
  int biggerPrecision = 19;
  const char *greetings = "Hello world";

  printf("|%.8s|\n", greetings);
  printf("|%.*s|\n", precision , greetings);
  printf("|%%|\n", precision, biggerPrecision);
  printf("|%.*s|\n", biggerPrecision , greetings);
}
