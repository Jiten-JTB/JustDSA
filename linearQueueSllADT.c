#include <stdio.h>
#include <stdlib.h>

// BluePrint of Single Linked List Node
typedef struct sllNode {
    int data;
    struct sllNode* next;
} lqNode;

// Global Variable
lqNode* f, *r;

// Create Single Linked List Node and Returns It's Address
lqNode* getLqNode()
{
    return (lqNode*) malloc(sizeof(lqNode));
}

// is Empty?
int isEmpty()
{
    if (f == NULL)
        // True
        return 1;
    // False
    return 0;
}

// Enqueue
void enqueue()
{
    // Creating newNode
    lqNode* newNode = getLqNode();

    if (f == NULL)
        // Setting up The Front Pointer for The Very Front Node
        f = newNode;
    else
        // Connecting Prev Rear Node with New Rear Node
        r -> next = newNode;

    // Setting up The Rear Pointer for The Latest Node
    r = newNode;

    // newNode Data
    printf("Enter The Element to Enqueue: ");
    scanf("%i", &(newNode -> data));
    
    // newNode Next
    newNode -> next = NULL;
}

// Dequeue
int dequeue()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
    {
        // Fetching Front Most Element
        int element = f -> data;

        // Temp Next 
        lqNode* tempNext = f -> next;

        // Delete Front Most Node
        free(f);
 
        // Setting up The Front Pointer for The Very Front Node
        f = tempNext;

        // Setting up The Rear Pointer for The Very Front Node
        if (f == NULL)
            r = NULL;

        return element;
    }
    return -1;
}

// Front or Peek
int front()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
        return f -> data;
    return -1;
}

// Rear
int rear()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
        return r -> data;
    return -1;
}

// Display
int display()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
        for (lqNode* ptr = f; ptr != NULL; ptr = ptr -> next)
            printf("%i\n", ptr -> data);
}

int main()
{
    int opNo, data;
    printf("\n----- Linear Queue by using Single Linked List  -----\n");

    while(1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%i", &opNo);

        switch(opNo)
        {
            case 0:
                return 0;
            case 1:
                printf("\n----- Enqueue -----\n");
                enqueue();
                break;
            case 2:
                printf("\n----- Dequeue -----\n");
                data = dequeue();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i has been Dequeued\n", data);
                break;
            case 3:
                printf("\n----- Front -----\n");
                data = front();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i is at Front of the Linear Queue\n", data);
                break;
            case 4:
                printf("\n----- Rear -----\n");
                data = rear();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i is at Rear of the Linear Queue\n", data);
                break;
            case 5:
                printf("\n----- Display -----\n");
                display();
                break;
            default:
                printf("\n----- Invalid Input -----\n");
        }
    }
    return 1;
}