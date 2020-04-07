#include <stdio.h>


int main()
{
  int precision = 8;
  int biggerPrecision = 16;
  int enteri = 170;
  const char *greetings = "Hello world";

  printf("s 1 : |%-.s|\n", greetings);
  printf("s 2 : |%.s|\n", greetings);
  printf("s 3 : |%8s|\n", greetings);
  printf("s 4 : |%.8s|\n", greetings);
  printf("s 5 : |%-s|\n", greetings);
  printf("s 6 : |%-.s|\n", greetings);
  printf("s 7 : |%-.*s|\n", precision, greetings);
  printf("s 8 : |%*s|\n", biggerPrecision, greetings);
  printf("s 9 : |%.*s|\n", biggerPrecision , greetings);
  printf("s 10 : |%-.*s|\n", biggerPrecision, greetings);
  printf("s 11 : |%-*s|\n", biggerPrecision , greetings);

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
