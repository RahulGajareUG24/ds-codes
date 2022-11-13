#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*hed;

void createLinkList(int n);
void reverseList();
void printList();

int main()
{
    int n;
		printf("\n\n Linked List : Create a singly linked list and print it in reverse order :\n");
		printf("------------------------------------------------------------------------------\n");
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createLinkList(n);		
    reverseList();
    printf("\n reverseList: \n");
    printList();
    getch();
    return 0;
}

void createLinkList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    hed = (struct node *)malloc(sizeof(struct node));
    if(hed == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        hed-> num = num;      
        hed-> nextptr = NULL; //Links the address field to NULL
        tmp = hed;
//Creates n nodes and adds to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
}

void reverseList()
{
    struct node *prevNode, *curNode;
 
    if(hed != NULL)
    {
        prevNode = hed;
        curNode = hed->nextptr;
        hed = hed->nextptr;
 
        prevNode->nextptr = NULL; //convert the first node as last
 
        while(hed != NULL)
        {
            hed = hed->nextptr;
            curNode->nextptr = prevNode;
 
            prevNode = curNode;
            curNode = hed;
        }
        hed = prevNode; //convert the last node as head
    }
}

void printList()
{
    struct node *tmp;
    if(hed == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = hed;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
}
 