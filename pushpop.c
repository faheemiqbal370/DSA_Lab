//push pop
#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int size;
  int top;
  int *arr;
  
};

int isEmpty(struct stack *ptr){
  if(ptr->top == -1){
    return 1;
  }
  else{
    return 0;
  }
}


int isFull(struct stack *ptr){
  if(ptr->top == ptr->size-1){
    return 1;
  }

else{
  return 0;
}
}

void push(struct stack * ptr, int value){
  if(isFull(ptr)){
    printf("Stack Overflow! cannot push %d to the Stack  \n", value);
  }
  else{
    ptr->top++;
    ptr->arr[ptr->top] = value;
  }
}



int pop(struct stack * ptr){
  if(isEmpty(ptr)){
    printf("Stack Underflow! cannot pop from the stack\n");
    return -1;
  }
  else{
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
 }
}


int main(){
  struct stack *s = (struct stack *)malloc(sizeof(struct stack));
  s->size = 5;
  s->top = -1;
  s->arr = (int *) malloc(s->size * sizeof(int));


  push(s, 57);
  push(s, 77);
  push(s, 32);
  push(s, 45);
  push(s, 95);        // Pushed five values to stack
  push(s, 51);        // Stack Overflow
  printf("After Pushing, Full %d\n", isFull(s));
  printf("After Pushing, Empty %d\n", isEmpty(s)); 



  printf("Popped %d from the Stack", pop(s));               // Last in is First Out



  return 0;
}