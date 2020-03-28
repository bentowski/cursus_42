#include <stdio.h>


int main()
{
  int precision = 8;
  int biggerPrecision = 16;
  int enteri = 170;
  const char *greetings = "Hello world";

  printf("s 1 : |%%/-\\.%x|\n", enteri);
  printf("s 2 : |%.x|\n", enteri);
  printf("s 3 : |%08x|\n", enteri);
  printf("s 4 : |%.08x|\n", enteri);
  printf("s 5 : |%-x|\n", enteri);
  printf("s 6 : |%-.x|\n", enteri);
  printf("s 7 : |%-.*x|\n", precision, enteri);
  printf("s 8 : |%*x|\n", biggerPrecision, enteri);
  printf("s 9 : |%.*x|\n", biggerPrecision , enteri);
  printf("s 10 : |%-.*x|\n", biggerPrecision, enteri);
  printf("s 11 : |%-*x|\n", biggerPrecision , enteri);

  printf("\n\n\n");

  printf("c 1 : |\\%-8c|\n", greetings[3]);
  printf("c 2 : |%8c|\n", greetings[3]);
  printf("c 3 : |%c|\n", greetings[3]);
  printf("c 4 : |%-c|\n", greetings[3]);
  printf("c 5 : |%-*c|\n", precision, greetings[3]);
  printf("c 6 : |%*c|\n", biggerPrecision, greetings[3]);
  printf("c 7 : |%-*c|\n", biggerPrecision, greetings[3]);

  printf("\n\n\n");

  printf("d 1 : |%.d|\n", enteri);
  printf("d 2 : |%-d|\n", enteri);
  printf("d 3 : |%*d|\n", precision, enteri);
  printf("d 4 : |%0d|\n", enteri);
  printf("d 5 : |%-.d|\n", enteri);
  printf("d 6 : |%0504d|\n", enteri);
  printf("d 7 : |%.0d|\n", enteri);
  printf("d 8 : |%-.0d|\n", enteri);
  printf("d 9 : |%-.*d|\n", precision, enteri);
  printf("d 10 : |%-*d|\n", precision, enteri);
  printf("d 11 : |%0*d|\n", precision, enteri);
}
