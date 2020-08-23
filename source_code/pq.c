#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pq.h"

// pointer to pointer to be able to change pointer address inside a function
void enqueue(pq ** front, pq ** rear,
  char data[STRLEN], int priority) {

  // define temporary structs
  pq * temp1, * temp2;
  // temp1 will contain the input values while temp2 will be transition
  temp1 = (pq * ) malloc(sizeof(pq)); // temp1 will remain in the heap linked somewhere
  // fill temp1 with input values	
  strcpy(temp1 -> data, data);
  temp1 -> priority = priority;
  temp1 -> next = NULL; // not linked to anything yet

  /* empty queue i.e. first value to enqueue
  assign both rear and front to temp1 */
  if ( * rear == NULL) {
    * rear = temp1;
    * front = * rear;
    // it is more important than front
  } else if (( * front) -> priority < priority) {
    // change front location to temp1 and make temp1 links to front
    temp1 -> next = * front;
    * front = temp1;
  } else {
    // new data is less important than rear
    if (( * rear) -> priority > priority) {
      // make rear temp1 as last element and make it links to itself
      ( * rear) -> next = temp1;
      * rear = temp1;

      // priority is between rear and front
    } else {
      // make temp2 the front for now
      temp2 = * front;
      /* loop over linked list comparing priorities 
      until you find the right place for the new data */
      while ((temp2 -> next) -> priority >= priority) {
        temp2 = temp2 -> next;
      }
      // now temp2 has the right place for the input priority
      // N.B. it changes 'next' of front as well
      temp1 -> next = temp2 -> next;
      temp2 -> next = temp1;
    }
  }
}

// it takes address i.e. pointers
char *execute(pq ** front, pq ** rear) {
  // temporary queues
  pq * temp;
  char *s = (char *)malloc(sizeof(STRLEN)); // to be able to return in it as not local
  int p;
  // Empty queue
  if (( * front == * rear) && ( * rear == NULL)) {
    puts("\n\tThe queue is empty");
    //exit(0);
  } else {
    // get task and priority to print
    //strcpy(s, (*front)->data);
    sprintf(s, ( * front) -> data);
    p = ( * front) -> priority;
    // change place of front
    temp = * front;
    * front = ( * front) -> next;

    if ( * rear == temp)
      * rear = ( * rear) -> next; // to make *rear NULL
    printf("\nTask (%s) with priority (%i) has been removed\n",
      s, p);
    free(temp); // it is not needed anymore (removed)
  }
  return s;
}

void display(pq * front, pq * rear) {
  if ((front == rear) && (rear == NULL)) {
    puts("\n\tThe queue is Empty");
  } else {
    puts("{");
    do {
      printf("\t{'task': %s, 'priority': %i}\n", front -> data, front -> priority);
      front = front -> next;
    } while (front != rear -> next); // because rear links to itself
    puts("}");
  }
}
