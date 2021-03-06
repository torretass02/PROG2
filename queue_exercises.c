#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "types.h"

/* Include here any other headers you need */

/**
 * @brief Returns a new queue that interleaves the elements in the first and 
 * second halves of a queue.
 *
 * Examples:
 *
 * Input:  [1, 2, 3, 4, 5, 6]
 * Output: [1, 4, 2, 5, 3, 6]
 *
 * Input:  [1, 2, 3, 4, 5]
 * Output: [1, 4, 2, 5, 3]
 *
 * @see https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
 *
 * @param q, pointer to the queue.
 *
 * @return A new queue with the elements in the first and second halves of q
 * interleaved. See example above.
 **/
Queue *interleave(Queue *q) {
  Queue *qinter = NULL;
  Queue *q1 = NULL;
  Queue *q2 = NULL; 
  int i, size;

  size = queue_size(q);

  qinter = queue_new();
  if (!qinter) {
    queue_free(qinter);
    return NULL;
  }

  q1 = queue_new();
  if (!q1) {
    queue_free(qinter);
    queue_free(q1);
    return NULL;
  }

  q2 = queue_new();
  if (!q2) {
    queue_free(qinter);
    queue_free(q1);
    queue_free(q2);
    return NULL;
  }
  
  if(size % 2 == 0){
    for(i=0; i<(size/2); i++){
      queue_push(q1, queue_pop(q));
    }

    for(i=(size/2); i<size; i++){
      queue_push(q2, queue_pop(q));
    }
  }
  else{
    for(i=0; i<(size/2)+1; i++){
      queue_push(q1, queue_pop(q));
    }

    for(i=(size/2)+1; i<size; i++){
      queue_push(q2, queue_pop(q));
    }
  }
  while(queue_isEmpty(q1) == FALSE || queue_isEmpty(q2) == FALSE){
    queue_push(qinter, queue_pop(q1));
    queue_push(qinter, queue_pop(q2));
  }

  queue_free(q1);
  queue_free(q2);
  return qinter;
}

/**
 * @brief Concatenates two queues by adding all the elements in the second queue
 * to the first one. Upon successful exit the first queue will contain the 
 * elements from both queues and the second queue will be empty. In case of 
 * error the two queues will be unchanged.
 *
 * Example:
 *
 * Before concatenation: qa = [1, 2, 3, 4, 5, 6]
 *                       qb = [1, 2, 3, 4]
 *
 * After concatenation:  qa = [1, 2, 3, 4, 5, 6, 1, 2, 3, 4]
 *                       qb = []
 *
 * @param qa, pointer to the first queue.
 * @param qb, pointer to the second queue.
 *
 * @return OK on success, ERROR if there is any error. In case of error the 
 * contents of both queues must remain unchanged.
 **/
Status concatenate(Queue *qa, Queue *qb) {
  Status st;
  int size_a, i;
  Queue *aux;
  const void *e;

  aux = queue_new();

  size_a = queue_size(qa);

  while(queue_isEmpty(qb)==FALSE){
    e = queue_pop(qb);
    if(queue_push(qa, e) == ERROR){
      queue_push(qb, e);
      for(i=0; i<size_a; i++){
        queue_push(aux, queue_pop(qa));
      }
      while(queue_isEmpty(qb)==FALSE){
        queue_push(qa, queue_pop(qb));
      }
      while(queue_isEmpty(qa)==FALSE){
        queue_push(qb, queue_pop(qa));
      }
      while(queue_isEmpty(aux)==FALSE){
        queue_push(qa, queue_pop(aux));
      }
      queue_free(aux);
      return ERROR;
    }
  }
  queue_free(aux);
  return OK;
}
