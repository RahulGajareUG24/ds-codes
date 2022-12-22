#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node *append(struct Node *head, int data)
{
    if (head == NULL) return newNode(data);

    struct Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode(data);
    return head;
}

void swap(struct Node *a, struct Node *b)
{
    if (a == NULL || b == NULL) {
        fprintf(stderr, "Error: invalid arguments to swap function.\n");
        exit(1);
    }

    int t = a->data;
    a->data = b->data;
    b->data = t;
}

struct Node *partition(struct Node *head, struct Node *end)
{
    if (head == NULL || end == NULL) {
        fprintf(stderr, "Error: invalid arguments to partition function.\n");
        exit(1);
    }

    if (head == end) {
        return head;
    }

    int pivot = end->data;
    struct Node *i = head;
    struct Node *j = head;

    while (j != end) {
        if (j->data < pivot) {
            swap(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap(i, end);
    return i;
}

void quickSort(struct Node *head, struct Node *end)
{
    if (head == NULL || end == NULL) {
        fprintf(stderr, "Error: invalid arguments to quickSort function.\n");
        exit(1);
    }

    if (head == end || head->next == end || head->next->next == end) {
        if (head->data > end->data) {
            swap(head, end);
        }
        return;
    }

    struct Node *p = partition(head, end);
    quickSort(head, p);
    quickSort(p->next, end);
}

struct Node *getTail(struct Node *head) {
    if (head == NULL) {
        fprintf(stderr, "Error: invalid argument to getTail function.\n");
        exit(1);
    }

    struct Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}

struct Node *generateList(int n) {
    struct Node *head = NULL;
    for (int i = 0; i < n; i++) {
        head = append(head, rand() % 1000);
    }
    return head;
}

void printList(struct Node *head) {
    printf("List = ");
    if (head == NULL) {
        printf("(empty).\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf(".\n");
}

int main(int argc, char **argv) {
    struct Node *a;
    int n = 10;

    srand(time(NULL));

    a = generateList(n);
    if (a == NULL) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    printList(a);
    quickSort(a, getTail(a));
    printList(a);

    printf("Press enter to continue...\n");
    getchar();

    while (a != NULL) {
        struct Node *temp = a;
        a = a->next;
        free(temp);
    }

    return 0;
}
