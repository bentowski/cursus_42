#include <stdio.h>


int main()
{
  int precision = 8;
  int biggerPrecision = 16;
  int enteri = 15253;
  const char *greetings = "Hello world";

  printf("p 1 : |%-.p|\n", enteri);
  printf("p 2 : |%.p|\n", enteri);
  printf("p 3 : |%8p|\n", enteri);
  printf("p 4 : |%.8p|\n", enteri);
  printf("p 5 : |%-p|\n", enteri);
  printf("p 6 : |%-.p|\n", enteri);
  printf("p 7 : |%-.*p|\n", precision, enteri);
  printf("p 8 : |%*p|\n", precision, enteri);
  printf("p 9 : |%.*p|\n", precision , enteri);
  printf("p 10 : |%-.*p|\n", precision, enteri);
  printf("p 11 : |%-*p|\n", precision , enteri);

  // printf("\n\n\n");
  //
  // printf("c 1 : |%-8c|\n", greetings[3]);
  // printf("c 2 : |%8c|\n", greetings[3]);
  // printf("c 3 : |%c|\n", greetings[3]);
  // printf("c 4 : |%-c|\n", greetings[3]);
  // printf("c 5 : |%-*c|\n", precision, greetings[3]);
  // printf("c 6 : |%*c|\n", biggerPrecision, greetings[3]);
  // printf("c 7 : |%-*c|\n", biggerPrecision, greetings[3]);
  //
  // printf("\n\n\n");
  //
  // printf("d 1 : |%.d|\n", enteri);
  // printf("d 2 : |%-d|\n", enteri);
  // printf("d 3 : |%*d|\n", precision, enteri);
  // printf("d 4 : |%0d|\n", enteri);
  // printf("d 5 : |%-.d|\n", enteri);
  // printf("d 6 : |%0504d|\n", enteri);
  // printf("d 7 : |%.0d|\n", enteri);
  // printf("d 8 : |%-.0d|\n", enteri);
  // printf("d 9 : |%-.*d|\n", precision, enteri);
  // printf("d 10 : |%-*d|\n", precision, enteri);
  // printf("d 11 : |%0*d|\n", precision, enteri);
}
