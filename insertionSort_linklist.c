#include <stdio.h>
#include <stdlib.h>

// A node in the linked list
struct node {
  int data;
  struct node *next;
};

// Create a new node with the given data
struct node* new_node(int data) {
  struct node* n = malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  return n;
}

// Insert a new node with the given data at the correct position in the list
void insert(struct node** head, int data) {
  // Create the new node
  struct node* new_node = new_node(data);

  // Handle the special case where the list is empty or the new node should be inserted at the beginning of the list
  if (*head == NULL || (*head)->data > data) {
    new_node->next = *head;
    *head = new_node;
    return;
  }

  // Find the correct position in the list to insert the new node
  struct node* current = *head;
  while (current->next != NULL && current->next->data < data) {
    current = current->next;
  }

  // Insert the new node
  new_node->next = current->next;
  current->next = new_node;
}

// Print the linked list
void print_list(struct node* head) {
  struct node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Sort the linked list using insertion sort
void insertion_sort(struct node** head) {
  // Create a dummy node to serve as the head of the sorted list
  struct node* dummy = new_node(0);
  dummy->next = *head;

  // Iterate through the list, inserting each element at the correct position in the sorted list
  struct node* current = *head;
  while (current != NULL) {
    struct node* next = current->next;
    insert(&dummy, current->data);
    current = next;
  }

  // Update the head of the list to point to the first element in the sorted list
  *head = dummy->next;
}

int main() {
  // Create an unsorted linked list
  struct node* head = new_node(5);
  head->next = new_node(3);
  head->next->next = new_node(2);
  head->next->next->next = new_node(1);
  head->next->next->next->next = new_node(4);

  // Print the list before sorting
  printf("Before sorting: ");
  print_list(head);

  // Sort the list
  insertion_sort(&head);

  // Print the list after sorting
  printf("After sorting: ");
  print_list(head);

  return 0;
}
