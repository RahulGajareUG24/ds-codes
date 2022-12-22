#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        fprintf(stderr, "Error allocating memory for new node.\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

void inorder(struct node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

#define ARRAY_SIZE 10

int main() {
  int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  struct node* root = NULL;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    root = insert(root, array[i]);
  }
    inorder(root);
    printf("\n");
    getchar();
    return 0;
}
