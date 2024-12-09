//circular queue
#include<stdio.h>
#include<stdlib.h>

struct Circularqueue{
  int size;
  int f;
  int r;
  int* arr;

};

int isEmpty(struct Circularqueue *q){
  if(q->r == q->f)
{
  return 1;
}
else
return 0;
}


int isFull(struct Circularqueue *q){
  if(((q->r+1)%q->size) == q->f){
  return 1;
}
else
return 0;
}



void enqueue(struct Circularqueue *q, int val){
  if(isFull(q)){
    printf("this queue is full\n");
  }
  else{
   
      q->r = (q->r+1)%q->size;
      q->arr[q->r] = val;
       printf("Enqueued Element: %d\n",val);
  }
}


int dequeue(struct Circularqueue *q){
  int a = 0;
  if(isEmpty(q)){
    printf("Queue is Empty\n");
  }
  else{
    q->f = (q->f+1)%q->size;
    a = q->arr[q->f];
     return a;
  }
}

int main (){
  struct Circularqueue q;
  q.size = 3;
  q.f = q.r = 0;
  q.arr = (int *) malloc(q.size*sizeof(int));
  


  enqueue(&q, 14);
  enqueue(&q, 17);
  enqueue(&q, 71);
   
   
  // enqueue(&q, 4);

  printf("Dequeuing element %d\n", dequeue(&q));            // First in First Out 
  printf("Dequeuing element %d\n", dequeue(&q));
  printf("Dequeuing element %d\n", dequeue(&q));

   if(isEmpty(&q)){
  printf("Queue is Empty\n");
  }

    if(isFull(&q)){
  printf("Queue is Full\n");
  }
 


  

  return 0;
}