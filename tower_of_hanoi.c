#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;


Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}


void towerOfHanoi(int numDisks, Stack *source, Stack *destination, Stack *auxiliary) {
    int moveCount = 0;

    
    for (int i = numDisks; i >= 1; i--) {
        push(source, i);
    }


    while (destination->top < numDisks - 1) {
        moveCount++;

        
        if (moveCount % 3 == 1) {
            
            int disk = pop(source);
            printf("Move disk %d from source to destination\n", disk);
            push(destination, disk);
        } 
        
        else if (moveCount % 3 == 2) {
            int disk = pop(source);
            printf("Move disk %d from source to auxiliary\n", disk);
            push(auxiliary, disk);
        } 
        
        else if (moveCount % 3 == 0) {
            int disk = pop(auxiliary);
            printf("Move disk %d from auxiliary to destination\n", disk);
            push(destination, disk);
        }

        
        printf("Source stack: ");
        printStack(source);
        printf("Auxiliary stack: ");
        printStack(auxiliary);
        printf("Destination stack: ");
        printStack(destination);
    }

    printf("Tower of Hanoi solved!\n");
}

int main() {
    int numDisks = 3; 

    
    Stack *source = createStack(numDisks);
    Stack *auxiliary = createStack(numDisks);
    Stack *destination = createStack(numDisks);


    towerOfHanoi(numDisks, source, destination, auxiliary);

    
    free(source->arr);
    free(auxiliary->arr);
    free(destination->arr);
    free(source);
    free(auxiliary);
    free(destination);

    return 0;
}