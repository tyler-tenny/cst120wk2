#include <stdio.h>

#define square(a) a*a

int factorial(const int * input) {
  int temp = *input;
  printf("%d! = %d", *input, *input);
  for (int i = (*input - 1); i > 0; --i) {
    printf("*%d", i);
    temp *= i;
  }
  printf("\n factorial is %d \n", temp);
  return temp;
}

int main() {
  char cont = 'y';
  while (cont == 'y' || cont == 'Y') {
   int input = 0;
   while (input < 3 || input > 9) {
     printf("Please enter an integer between 3 and 9: ");
     scanf("%d", &input);
   }
   int sqInput = square(input);
   printf("%d squared is %d \n", input, sqInput);
   int faInput = factorial(&input);
   if (faInput < sqInput) {
     printf("Yea! Factorial is less than the square! \n");
   }

   printf("Please press y to continue: ");
   scanf(" %c", &cont);
  }
}
