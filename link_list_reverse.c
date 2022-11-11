#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*hed;
typedef struct node * NodeAddress;

void createNodeList(int n);     //function to create the list
void reverseDispList();         //function to convert the list in reverse
void displayList();             //function to display the list

int main()
{
    int n;
		printf("\n\n Linked List : Create a singly linked list and print it in reverse order :\n");
		printf("------------------------------------------------------------------------------\n");
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list are : \n");		
    printList();
    reverseList();
    printf("\n The list in reverse are :  \n");
    printList();
    return 0;
}

NodeAddress createLinkList(int n)
{
	NodeAddress fnNode= NULL;
	NodeAddress tmp= NULL;
    int num, i;
	NodeAddress hed = (struct node *)malloc(sizeof(struct node));

    if(hed == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        hed->num = num;      
        hed->nextptr = NULL; // links the address field to NULL
        tmp = hed;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
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

NodeAddress reverseList()
{
    NodeAddress prevNode= NULL;
    NodeAddress curNode= NULL;
 
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

