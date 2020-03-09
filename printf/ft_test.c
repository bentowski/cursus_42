#include <stdio.h>


int main()
{
  int precision = 8;
  int biggerPrecision = 16;
  const char *greetings = "Hello world";

  printf("1 : |%-.8s|\n", greetings);
  printf("2 : |%.8s|\n", greetings);
  printf("3 : |%8s|\n", greetings);
  printf("4 : |%.s|\n", greetings);
  printf("5 : |%-s|\n", greetings);
  printf("6 : |%-.s|\n", greetings);
  printf("7 : |%-.*s|\n", precision, greetings);
  printf("8 : |%*s|\n", biggerPrecision, greetings);
  printf("9 : |%.*s|\n", biggerPrecision , greetings);
  printf("10 : |%-.*s|\n", biggerPrecision, greetings);
  printf("11 : |%-*s|\n", biggerPrecision , greetings);
}
