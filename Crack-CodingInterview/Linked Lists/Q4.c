/*Write a code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or
equal to x. If x is contained in list, the values of x only need to be after the elements less than x. The partion element x can
appear anywhere in the "right partition", it does not appear between the left and right positions.

eg : position = 5
Input : 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
Output : 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
*/

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
    printf("Elements in Singly linkedlist are : \n");
    while(Head != NULL)
    {
        printf("|%d | ->", Head -> data);
        Head = Head -> next;
    }
    printf("NULL \n");
}

void Partition(PPNODE Head, int iNo)
{
    PNODE leftHead = NULL;
    PNODE leftTail = NULL;

    PNODE rightHead = NULL;
    PNODE rightTail = NULL;

    PNODE temp = *Head;

    while(temp != NULL)
    {
        PNODE next = temp -> next;
        temp -> next = NULL;

        if(temp -> data < iNo)
        {
            if(leftHead == NULL)
            {
                leftHead = temp;
                leftTail = leftHead;
            }
            else
            {
                leftTail -> next = temp;
                leftTail = temp;
            }
        }
        else
        {
            if(rightHead == NULL)
            {
                rightHead = temp;
                rightTail = rightHead;
            }
            else
            {
                rightTail -> next = temp;
                rightTail = temp;
            }
        }
        temp = next;
    }
    if(leftTail != NULL)
    {
        leftTail -> next = rightHead;
        *Head = leftHead;
    }
    else
    {
        *Head = rightHead;
    }
}

int main()
{
    PNODE First = NULL;
    int iValue = 0;

    InsertFirst(&First, 3);
    InsertFirst(&First, 5);
    InsertFirst(&First, 8);
    InsertFirst(&First, 5);
    InsertFirst(&First, 10);
    InsertFirst(&First, 2);
    InsertFirst(&First, 1);
    Display(First);

    printf("Please enter partition value \n");
    scanf("%d", &iValue);

    Partition(&First, iValue);
    Display(First);

    return 0;
}