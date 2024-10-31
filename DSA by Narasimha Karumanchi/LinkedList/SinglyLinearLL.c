#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int iNo)
{
    //S :1 Allocate Memory of Node
    //S :2 Initailize memory
    //S :3 Check LL is empty or not
    //S :4 If LL is empty store address of new node in First
    //S :5 Otherwise Store the address of inside next pointer of old first node
    //S :6 Update first pointer with the address of new node

    PNODE newn = NULL;

    //S1
    newn = (PNODE)malloc(sizeof(NODE));

    //S2
    newn -> data = iNo;
    newn -> next = NULL;

    //S3
    if(*Head == NULL)
    {//S4
        *Head = newn;
    }
    else
    {//S5
        newn -> next = *Head;
    //S6
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int iNo)
{
    //S :1 Allocate Memory of Node
    //S :2 Initailize memory
    //S :3 Check LL is empty or not
    //S :4 If LL is empty store address of new node in First
    //S :5 Otherwise Store the address of inside next pointer of old first node
    //S :6 Update first pointer with the address of new node

    PNODE newn = NULL;
    //temporary pointer taken as it is call by address
    PNODE temp = *Head;
    //S1
    newn = (PNODE)malloc(sizeof(NODE));

    //S2
    newn -> data = iNo;
    newn -> next = NULL;

    //S3
    if(*Head == NULL)
    {//S4
        *Head = newn;
    }
    else
    {//S5
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    //S6
        
    }
}

//Precedence and operator
void DeleteFirst(PPNODE Head)
{
    //Call by address as fucntion is going to get change inside the function
    //It will be PPNODE
    //Free function used in C

    PNODE temp = *Head;

    if(*Head == NULL)   //LL is empty
    {
        return; //function return value is void so only "return"
    }
    else if((*Head) -> next == NULL)    //LL conatins one node
    {
        free(*Head);
        *Head = NULL;
    }
    else        //LL contains more than one node
    {
        //*Head = *Head -> next;Free(*Head); will turn into memory leak.
        //It is only breaking the link, but not deallocating memory
        //So to avoid it we need temporary pointer

        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    //Call by address as fucntion is going to get change inside the function
    //It will be PPNODE
    //Free function used in C

    PNODE temp = *Head;

    if(*Head == NULL)   //LL is empty
    {
        return; //function return value is void so only "return"
    }
    else if((*Head) -> next == NULL)    //LL conatins one node
    {
        free(*Head);
        *Head = NULL;
    }
    else        //LL contains more than one node
    {
        while(temp -> next ->next != NULL)  //Type 3
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void Display(PNODE Head)
{
    //No tempoary varaible as it is call by value
    printf("Nodes in LL are : \n");
    while(Head != NULL)
    {
        printf("|%d|->\t", Head ->data);
        Head = Head -> next;
    }
    printf("NULL \n");
}

int Count(PNODE Head)
{   
    int iCount = 0;
    //No tempoary varaible as it is call by value
    while(Head != NULL)
    {   
        iCount++;
        Head = Head -> next;
    }
    return iCount;
}

void InsertAtPos(PPNODE Head, int iNo, int ipos)
{
    int iLength = 0;
    iLength = Count(*Head); //Calculate Length of LL

    PNODE newn = NULL;
    int iCnt = 0;
    PNODE temp = *Head;

    //Filter
    if((ipos < 1) || (ipos > iLength +1)) //Invalid position
    {
        printf("Invalid position \n");
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(Head,iNo);
    }
    else if(ipos == iLength+1)
    {
        InsertLast(Head, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;

        for(iCnt = 1; iCnt< ipos-1; iCnt++)
        {
            temp = temp -> next;
        }
        //Sequence is important
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int ipos)
{
    int iLength = 0;
    iLength = Count(*Head); //Calculate Length of LL

    PNODE temp = *Head;
    PNODE tempX = NULL;
    int iCnt = 0;

    //Filter
    if((ipos < 1) || (ipos > iLength)) //Invalid position
    {
        printf("Invalid position \n");
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst(Head);
    }
    else if(ipos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }
        tempX = temp -> next;

        //Sequence is imporatant
        temp -> next = temp -> next -> next; //arrow jodun ghya
        free(tempX);
    }
}

int main()
{
    PNODE First = NULL;
    //Funcation jr call by dddress asel tr temporary pointer gheto karan aaplayla main madhla value ghalvaichi nahi a.

    int iRet = 0;

    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    InsertLast(&First,121);
    Display(First);

    iRet = Count(First);
    printf("Number of Nodes are : %d\n", iRet);

    DeleteFirst(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of Nodes are : %d\n", iRet); 

    DeleteLast(&First);
    Display(First);   
    iRet = Count(First);
    printf("Number of Nodes are : %d\n", iRet); 

    InsertAtPos(&First,69 ,2);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&First, 3);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    return 0;
}   