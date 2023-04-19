#include <stdio.h>
#include <stdlib.h>

int strLength(char * input) {
  int len = 0;
  //iterate through array and count chars until \n
  for (; input[len]; ++len) {}
  return len;
}

int isPalindrome(char * input, const int * len) {
  int count = 0;
  //iterate through array and compare i, starting left, and len - (i+1), starting right, so that we skip \n.
  //if any character doesn't match, return false
  for  (int i = 0; i < *len; ++i) {
    if (input[i] != input[*len-(i+1)]) {
      return 0;
    }
  }
  return 1;
}

void shiftLeft(char * input, int pos) {
  //remove a character at pos and move the array to the left to replace it.
  for (; input[pos]; ++pos) {
    input[pos] = input[pos + 1];
  }
}

void removeSpec(char * input) {
  int i = 0;
  //check for any characters that are not strictly letters a-z, upper or lower case, then shift left
  for (int i = 0; input[i]; ++i) {
    if (input[i] < 65 || input[i] > 122) {
      shiftLeft(input, i);
      --i;
    }
  }
  printf("%s \n", input);
}

int main() {
  char cont = 'y';
  while (cont == 'y' || cont == 'Y') {
    printf("Welcome. Please enter a palindrome: ");
    //create a new char pointer and then allocate up to 51 chars of memory
    char * input = malloc(sizeof(char) * 51);
    scanf("%[^\n]", input);
    //remove any special characters (anything not a-z)
    removeSpec(input);
    //collect length
    int len = strLength(input);
    //check if it is a palindrome
    int result = isPalindrome(input, &len);
    //return result
    if (result == 0) {
      printf("Your string is not a palindrome.\n");
    }
    else if (result == 1) {
      printf("Nice palindrome!\n");
    }
    //flush buffer before continue
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
    //deallocate memory for input
    free(input);
    //change to null pointer away from deallocated memory
    input = NULL;
    //continue loop and flush buffer for next input.
    printf("Please enter y to continue: ");
    scanf(" %c", &cont);
    while ((c = getchar()) != '\n' && c != EOF);
  }
}
