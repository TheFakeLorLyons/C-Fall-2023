/* From A Book on C Pg 471 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define   qEMPTY      0
#define   qFULL       10000

typedef   unsigned int         data;
typedef   enum {false, true}   boolean;

struct elem {                   /* an element in the queue */
   data         d;
   struct elem  *next;
};

typedef struct elem   elem;
struct queue {
   int    cnt;                  /* a count of the elements */
   elem   *front;               /* ptr to the front element */
   elem   *rear;                /* ptr to the rear element */
};

typedef   struct queue   queue;
void      qinitialize(queue *q);
void      enqueue(data d, queue *q);
data      dequeue(queue *q);
data      front(const queue *q);
boolean   qempty(const queue *q);
boolean   qfull(const queue *q);