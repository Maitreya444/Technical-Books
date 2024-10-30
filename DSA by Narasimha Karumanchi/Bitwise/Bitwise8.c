#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
typedef unsigned int UINT;

BOOL CheckBit(UINT iNo, UINT iPos)
{   
    UINT iMask = 0X00000001;
    UINT iResult = 0;

    if((iPos < 1) || (iPos > 32))
    {
        printf("Invalid Position\n");
        return FALSE;
    }

    iMask = iMask << (iPos - 1);

    iResult = iNo & iMask;

    if(iResult == iMask)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    UINT iValue = 0;
    UINT iBit = 0;
    BOOL bRet = FALSE;

    printf("Enter a Number \n");
    scanf("%d", &iValue);

    printf("Enter the bit which you want to edit \n");
    scanf("%d", &iBit);

    bRet = CheckBit(iValue, iBit);

    if(bRet == TRUE)
    {
        printf("Bit is ON \n");
    }
    else
    {
        printf("Bit is OFF \n");
    }

    return 0;
}   