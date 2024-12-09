//  Program in C Create a LinkedList input elements and search for an element if present multiple times delete and keep only one copy of that element 


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to remove duplicates from the linked list
void removeDuplicates(Node *head) {
    Node *current = head;
    Node *prev = NULL;
    Node *temp;

    while (current != NULL) {
        prev = current;
        temp = current->next;
        while (temp != NULL) {
            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    int n, element;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insertEnd(&head, element);
    }
    
    printf("Original List: ");
    displayList(head);
    
    removeDuplicates(head);
    
    printf("List after removing duplicates: ");
    displayList(head);
    
    return 0;
}