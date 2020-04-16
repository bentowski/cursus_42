# include "ft_printf.h"


int main()
{
  int precision;
  int enteri;
  char *greetings;

  greetings = "test juste comme";
  precision = 21;
  enteri = 461984561;

  // // ======== Test d ============
  printf("u 1 : |%.u|\n", enteri);
  ft_printf("u 1 : |%.u|\n\n", enteri);
  printf("u 2 : |%-u|\n", enteri);
  ft_printf("u 2 : |%-u|\n\n", enteri);
  printf("u 3 : |%*u|\n", precision, enteri);
  ft_printf("u 3 : |%*u|\n\n", precision, enteri);
  printf("u 4 : |%0u|\n", enteri);
  ft_printf("u 4 : |%0u|\n\n", enteri);
  printf("u 5 : |%-.u|\n", enteri);
  ft_printf("u 5 : |%-.u|\n\n", enteri);
  printf("u 6 : |%04u|\n", enteri);
  ft_printf("u 6 : |%04u|\n\n", enteri);
  printf("u 7 : |%.0u|\n", enteri);
  ft_printf("u 7 : |%.0u|\n\n", enteri);
  printf("u 8 : |%-.0u|\n", enteri);
  ft_printf("u 8 : |%-.0u|\n\n", enteri);
  printf("u 9 : |%-.*u|\n", precision, enteri);
  ft_printf("u 9 : |%-.*u|\n\n", precision, enteri);
  printf("u 10 : |%-*u|\n", precision, enteri);
  ft_printf("u 10 : |%-*u|\n\n", precision, enteri);
  printf("u 11 : |%0*u|\n", precision, enteri);
  ft_printf("u 11 : |%0*u|\n\n\n\n\n", precision, enteri);

  // ======== Test i ============
  printf("i 1 : |%.i|\n", enteri);
  ft_printf("i 1 : |%.i|\n\n", enteri);
  printf("i 2 : |%-i|\n", enteri);
  ft_printf("i 2 : |%-i|\n\n", enteri);
  printf("i 3 : |%*i|\n", precision, enteri);
  ft_printf("i 3 : |%*i|\n\n", precision, enteri);
  printf("i 4 : |%0i|\n", enteri);
  ft_printf("i 4 : |%0i|\n\n", enteri);
  printf("i 5 : |%-.i|\n", enteri);
  ft_printf("i 5 : |%-.i|\n\n", enteri);
  printf("i 6 : |%04i|\n", enteri);
  ft_printf("i 6 : |%04i|\n\n", enteri);
  printf("i 7 : |%.0i|\n", enteri);
  ft_printf("i 7 : |%.0i|\n\n", enteri);
  printf("i 8 : |%-.0i|\n", enteri);
  ft_printf("i 8 : |%-.0i|\n\n", enteri);
  printf("i 9 : |%-.*i|\n", precision, enteri);
  ft_printf("i 9 : |%-.*i|\n\n", precision, enteri);
  printf("i 10 : |%-*i|\n", precision, enteri);
  ft_printf("i 10 : |%-*i|\n\n", precision, enteri);
  printf("i 11 : |%0*i|\n", precision, enteri);
  ft_printf("i 11 : |%0*i|\n\n\n\n\n", precision, enteri);


  // ============ Test x & X ===========
  printf("x 1 : |%.x|\n", enteri);
  ft_printf("x 1 : |%.x|\n\n", enteri);
  printf("x 2 : |%-x|\n", enteri);
  ft_printf("x 2 : |%-x|\n\n", enteri);
  printf("x 3 : |%*x|\n", precision, enteri);
  ft_printf("x 3 : |%*x|\n\n", precision, enteri);
  printf("x 4 : |%0x|\n", enteri);
  ft_printf("x 4 : |%0x|\n\n", enteri);
  printf("x 5 : |%-.x|\n", enteri);
  ft_printf("x 5 : |%-.x|\n\n", enteri);
  printf("x 6 : |%04x|\n", enteri);
  ft_printf("x 6 : |%04x|\n\n", enteri);
  printf("x 7 : |%.0x|\n", enteri);
  ft_printf("x 7 : |%.0x|\n\n", enteri);
  printf("x 8 : |%-.0x|\n", enteri);
  ft_printf("x 8 : |%-.0x|\n\n", enteri);
  printf("x 9 : |%-.*x|\n", precision, enteri);
  ft_printf("x 9 : |%-.*x|\n\n", precision, enteri);
  printf("x 10 : |%-*x|\n", precision, enteri);
  ft_printf("x 10 : |%-*x|\n\n", precision, enteri);
  printf("x 11 : |%0*x|\n", precision, enteri);
  ft_printf("x 11 : |%0*x|\n\n\n\n\n", precision, enteri);

  // =========== Test p ==========
  printf("p 1 : |%p|\n", &enteri);
  ft_printf("p 1 : |%.p|\n\n", &enteri);
  printf("p 2 : |%-p|\n", &enteri);
  ft_printf("p 2 : |%-p|\n\n", &enteri);
  printf("p 3 : |%*p|\n", precision, &enteri);
  ft_printf("p 3 : |%*p|\n\n", precision, &enteri);
  printf("p 4 : |%p|\n", &enteri);
  ft_printf("p 4 : |%p|\n\n", &enteri);
  printf("p 5 : |%-p|\n", &enteri);
  ft_printf("p 5 : |%-.p|\n\n", &enteri);
  printf("p 6 : |%4p|\n", &enteri);
  ft_printf("p 6 : |%4p|\n\n", &enteri);
  printf("p 7 : |%p|\n", &enteri);
  ft_printf("p 7 : |%.p|\n\n", &enteri);
  printf("p 8 : |%-p|\n", &enteri);
  ft_printf("p 8 : |%-.p|\n\n", &enteri);
  printf("p 9 : |%-*p|\n", precision, &enteri);
  ft_printf("p 9 : |%-.*p|\n\n", precision, &enteri);
  printf("p 10 : |%-*p|\n", precision, &enteri);
  ft_printf("p 10 : |%-*p|\n\n", precision, &enteri);
  printf("p 11 : |%*p|\n", precision, &enteri);
  ft_printf("p 11 : |%*p|\n\n\n\n\n", precision, &enteri);


  // =========== Test s ==========
  printf("s 1 : |%-.s|\n", greetings);
  ft_printf("s 1 : |%-.s|\n\n", greetings);
  printf("s 2 : |%.s|\n", greetings);
  ft_printf("s 2 : |%.s|\n\n", greetings);
  printf("s 3 : |%-8s|\n", greetings);
  ft_printf("s 3 : |%-8s|\n\n", greetings);
  printf("s 4 : |%.32s|\n", greetings);
  ft_printf("s 4 : |%.32s|\n\n", greetings);
  printf("s 5 : |%-s|\n", greetings);
  ft_printf("s 5 : |%-s|\n\n", greetings);
  printf("s 6 : |%-.s|\n", greetings);
  ft_printf("s 6 : |%-.s|\n\n", greetings);
  printf("s 7 : |%-.*s|\n", precision, greetings);
  ft_printf("s 7 : |%-.*s|\n\n", precision, greetings);
  printf("s 8 : |%*s|\n", precision, greetings);
  ft_printf("s 8 : |%*s|\n\n", precision, greetings);
  printf("s 9 : |%.*s|\n", precision , greetings);
  ft_printf("s 9 : |%.*s|\n\n", precision , greetings);
  printf("s 10 : |%-.*s|\n", precision, greetings);
  ft_printf("s 10 : |%-.*s|\n\n", precision, greetings);
  printf("s 11 : |%-*s|\n", precision , greetings);
  ft_printf("s 11 : |%-*s|\n\n\n\n\n", precision , greetings);


  //======== Test c ==========
  printf("c 1 : |%-8c|\n", enteri);
  ft_printf("c 1 : |%-8c|\n\n", enteri);
  printf("c 2 : |%8c|\n", enteri);
  ft_printf("c 2 : |%8c|\n\n", enteri);
  printf("c 3 : |%c|\n", enteri);
  ft_printf("c 3 : |%c|\n\n", enteri);
  printf("c 4 : |%-c|\n", enteri);
  ft_printf("c 4 : |%-c|\n\n", enteri);
  printf("c 5 : |%-*c|\n", precision, enteri);
  ft_printf("c 5 : |%-*c|\n\n", precision, enteri);
  printf("c 6 : |%*c|\n", precision, enteri);
  ft_printf("c 6 : |%*c|\n\n", precision, enteri);
  printf("c 7 : |%-*c|\n", precision, enteri);
  ft_printf("c 7 : |%-*c|\n\n\n\n\n", precision, enteri);



  // ======== Test d ============
  printf("d 1 : |%.d|\n", enteri);
  ft_printf("d 1 : |%.d|\n\n", enteri);
  printf("d 2 : |%-d|\n", enteri);
  ft_printf("d 2 : |%-d|\n\n", enteri);
  printf("d 3 : |%*d|\n", precision, enteri);
  ft_printf("d 3 : |%*d|\n\n", precision, enteri);
  printf("d 4 : |%0d|\n", enteri);
  ft_printf("d 4 : |%0d|\n\n", enteri);
  printf("d 5 : |%-.d|\n", enteri);
  ft_printf("d 5 : |%-.d|\n\n", enteri);
  printf("d 6 : |%04d|\n", enteri);
  ft_printf("d 6 : |%04d|\n\n", enteri);
  printf("d 7 : |%.0d|\n", enteri);
  ft_printf("d 7 : |%.0d|\n\n", enteri);
  printf("d 8 : |%-.0d|\n", enteri);
  ft_printf("d 8 : |%-.0d|\n\n", enteri);
  printf("d 9 : |%-.*d|\n", precision, enteri);
  ft_printf("d 9 : |%-.*d|\n\n", precision, enteri);
  printf("d 10 : |%-*d|\n", precision, enteri);
  ft_printf("d 10 : |%-*d|\n\n", precision, enteri);
  printf("d 11 : |%0*d|\n", precision, enteri);
  ft_printf("d 11 : |%0*d|\n\n\n\n\n", precision, enteri);


}
