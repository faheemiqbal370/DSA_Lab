//Queue using array
#include<stdio.h>
#include<stdlib.h>

struct queue{
  int size;
  int f;
  int r;
  int* arr;

};

int isEmpty(struct queue *q){
  if(q->r == q->f)
{
  return 1;
}
else
return 0;
}


int isFull(struct queue *q){
  if(q->r == q->size-1)
{
  return 1;
}
else
return 0;
}



void enqueue(struct queue *q, int val){
  if(isFull(q)){
    printf("this queue is Full\n");
  }
  else{
      q->r++;
      q->arr[q->r] = val;
      printf("Enqueued Element: %d\n",val);
  }
}


int dequeue(struct queue *q){
  int a = -1;
  if(isEmpty(q)){
    printf("Queue is Empty\n");
  }
  else{
    q->f++;
    a = q->arr[q->f];
     return a;
  }
}

int main (){
  struct queue q;
  q.size = 4;
  q.f = q.r = -1;
  q.arr = (int *) malloc(q.size*sizeof(int));
  

  enqueue(&q, 12);
  enqueue(&q, 15);
  enqueue(&q, 7);
  enqueue(&q, 45);

  printf("Dequeuing element %d\n", dequeue(&q));            // First in First Out 
  printf("Dequeuing element %d\n", dequeue(&q));
  printf("Dequeuing element %d\n", dequeue(&q));

  


   if(isEmpty(&q)){
  printf("Queue is Empty\n");
  }

    if(isFull(&q)){
  printf("Queue is Full\n");
  }

  enqueue(&q, 15);
  enqueue(&q, 15);
  enqueue(&q, 15);

  

  return 0;
}