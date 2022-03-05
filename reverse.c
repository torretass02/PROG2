
#include "stack_fDoble.h"
#include <string.h>
#include <stdlib.h>
/* Include here any other headers you need */

/**
 * @brief: Reverses a string
 * @param str, String to reverse
 * @return A newly allocated string with the reversed string
 **/

char *string_invert(char *str) {
  Stack *s = NULL;
  int i;
  char *strout;
  

  s = stack_init();

  for(i=0; i<sizeof(str); i++){

    stack_push(s, &str[i]);
  }

  strout = malloc(stack_size(s));

  for(i=0; i<sizeof(str); i++){
    strout[i] = *(char*)stack_pop(s);
  }
  
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
  /*int i;
  Stack *s;
  char e;

  s = stack_init();

  for(i=0; i<sizeof(strin); i++){
    if(strin[i] == '\0'){
      stack_push(s, strin[i]);
    }
    else{
      while(stack_isEmpty(s) == FALSE){
        e = stack_pop(s);
        strcat(strout[i], e);
      }
    }
  }
  while(stack_isEmpty(s) == FALSE){
    e = stack_pop(s);
    strcat(strout[i], e);
  }

  stack_free(s);*/
  return OK;
};