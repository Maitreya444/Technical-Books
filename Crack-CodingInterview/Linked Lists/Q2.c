//Implement an algorithm to find the kth element of a singly linked list

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
    printf("Elements in LL are : \n");

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

void kElement(PNODE Head, int iNo)
{
    int iLength = 0;
    PNODE temp = Head;
    int iCnt = 0;

    iLength = Count(Head);

    if((iNo <0 ) && (iNo > iLength))
    {
        printf("Invalid value of k \n");
        return;
    }

    if(iNo == 0)
    {
        printf("%d\n", Head -> data);
    }

    else if(iNo == iLength)
    {
        while(temp-> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next;
        printf("%d\n", temp -> data);
    }

    else
    {   
        for(iCnt = 1; iCnt < iLength - iNo +1; iCnt++)
        {
            temp = temp -> next;
        }
        printf("%d\n", temp -> data);
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int k = 0;
    int iRet2 = 0;

    InsertFirst(&First,411);
    InsertFirst(&First,401);
    InsertFirst(&First,371);
    InsertFirst(&First,251);
    InsertFirst(&First,201);
    InsertFirst(&First,171);
    InsertFirst(&First,151);
    InsertFirst(&First,111);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    Display(First);
    iRet = Count(First);
    printf("Count of elements in LL is : %d\n", iRet);

    printf("Please Enter value of k \n");
    scanf("%d", &k);

    kElement(First, k);

    return 0;
}