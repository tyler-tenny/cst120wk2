#include <stdio.h>

void getInput(int * input) {
  printf("Please enter input: ");
  scanf("%d", input);
}

float percentage(int * actual, int * possible) {
  float actualF = (float)(*actual);
  float possibleF = (float)(*possible);
  float result = actualF / possibleF;
  result *= 100;
  printf("%f \n", result);
  return result;
}

int roundG(const float * toRound) {
  float temp = * toRound;
  int result = (int)(temp + .5);
  return result;
}

void print(int * result) {
  printf("Grade: %d \n", *result);
  if (*result >= 90) {
    printf("Excellent! \n");
  }
  else if (*result >= 80 && *result < 90) {
    printf("Bad :/ \n");
  }
  else if (*result >= 70 && *result < 80) {
    printf("Catastrophe :( \n");
  }
  else if (*result >= 60 && *result < 70) {
    printf("Death X( \n");
  }
  else if (*result < 60) {
    printf("F! \n");
  }
}

int main() {
  char cont = 'y';
  while (cont == 'y' || cont == 'Y') {
    int possible = 0;
    printf("Welcome. Please enter the total possible test score: ");
    scanf("%d", &possible);

    int actual = 0;
    printf("Please enter the actual student score: ");
    scanf("%d", &actual);
    
    float gradePer = percentage(&actual, &possible);
    int grade = roundG(&gradePer);

    print(&grade);

    printf("Type y if you would like to continue. ");
    scanf(" %c", &cont);
  }
}
        
  //collect number of digits before decimal
  //
  //set up arra
