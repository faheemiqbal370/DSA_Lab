// preorder traversal
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    // Visit the root
    printf("%d ", node->data);
    
    // Traverse the left subtree
    preorderTraversal(node->left);
    
    // Traverse the right subtree
    preorderTraversal(node->right);
}

int main() {
    // Creating a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder traversal of the binary tree is: ");
    preorderTraversal(root);
    
    return 0;
}
