#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// Utility function to create a new node
struct Node *newNode(int data) {
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Utility function to swap two integers
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to sort a linked list using selection sort
void selectionSort(struct Node *head) {
  struct Node *current, *min;

  // Traverse the list
  for (current = head; current->next != NULL; current = current->next) {
    // Find the minimum element in the unsorted list
    min = current;
    for (struct Node *node = current->next; node != NULL; node = node->next) {
      if (node->data < min->data) {
        min = node;
      }
    }

    // Swap the minimum element with the current element
    swap(&current->data, &min->data);
  }
}

// Utility function to print the linked list
void printList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // Create a linked list
  struct Node *head = newNode(5);
  head->next = newNode(4);
  head->next->next = newNode(3);
  head->next->next->next = newNode(2);
  head->next->next->next->next = newNode(1);

  // Print the unsorted list
  printf("Unsorted list: ");
  printList(head);

  // Sort the list
  selectionSort(head);

  // Print the sorted list
  printf("Sorted list: ");
  printList(head);
    getch();
    return 0;
}
