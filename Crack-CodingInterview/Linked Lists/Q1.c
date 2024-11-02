//Remove Duplicate element from the linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next; 
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof (NODE));
    newn -> data = iNo;
    newn -> next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        newn -> next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    printf("Elements from Singly linkedlist is : \n");

    while(Head != NULL)
    {
        printf("|%d |-> ", Head -> data);
        Head = Head -> next;
    }
    printf("NULL \n");
}

int Count(PNODE Head)
{   
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }
    return iCnt;
}

void DeleteDuplicate(PPNODE Head)
{
    PNODE current = *Head;
    PNODE temp = NULL;
    PNODE duplicate = NULL;

    while(current != NULL && current -> next != NULL)
    {   
        temp = current;
        while(temp -> next != NULL)
        {

        
            if(current -> data == temp -> next -> data)
            {
                duplicate = temp -> next;
                temp -> next = temp -> next -> next;
                free(duplicate);
            }
            else
            {
                temp = temp -> next;
            }
        }
        current = current -> next;
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,151);
    InsertFirst(&First,121);
    InsertFirst(&First,51);
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    Display(First);
    iRet = Count(First);
    printf("Count of Elements in Linkedlist is : %d\n", iRet);

    DeleteDuplicate(&First);
    Display(First);
    iRet = Count(First);
    printf("Count of Elements in Linkedlist is : %d\n", iRet);

    return 0;
}