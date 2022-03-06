
#include "stack_fDoble.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief: Reverses a string
 * @param str, String to reverse
 * @return A newly allocated string with the reversed string
 **/

char *string_invert(char *str) {
  if(!str) return NULL;
  if(strlen(str)==0) return NULL;

  Stack *s = NULL;
  int i;
  char *strout;
  char *e;
  
  s = stack_init();

  for(i=0; i<strlen(str); i++){

    stack_push(s, &str[i]);
  }

  strout = malloc(stack_size(s));

  for(i=0; i<strlen(str); i++){
    e = stack_pop(s);
    strout[i] = e[0];
  }
  
  stack_free(s);
  return strout;
}

/**
 * @brief: Reverse the words of an input string to an output string.
 *
 * @example: "Hello World" => "olleH dlroW"
 * The words in the input string are separated by a space character.
 * The strings may not overlap, and the destination string strout
 * must be large enough to receive the inverted expression.
 *
 * @param strout, Pointer to the output buffer
 * @param strin, Pointer to the input expression
 * @return The function returns OK or ERROR
 **/

Status reverseWords(char *strout, char *strin) {
  if(!strout || !strin) return ERROR;
  if(strlen(strin)==0) return ERROR;

  int i, j=0;
  Stack *s;
  char *e;

  s = stack_init();

  for(i=0; i<strlen(strin); i++){
    if(strin[i] != ' '){
      stack_push(s, &strin[i]);
    }
    else{
      while(stack_isEmpty(s) == FALSE){
        e = stack_pop(s);
        strout[j]=e[0];
        j++;
      }
      strout[j]=' ';
      j++;
    }
  }
  while(stack_isEmpty(s) == FALSE){
    e = stack_pop(s);
    strout[j]=e[0];
    j++;
  }

  stack_free(s);
  return OK;
}