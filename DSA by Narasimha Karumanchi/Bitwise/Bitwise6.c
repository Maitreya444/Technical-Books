#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
typedef unsigned int UINT;

BOOL CheckBit(UINT iNo)
{
    UINT iMask = 0X108;
    UINT iResult = 0;

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
    BOOL bRet = FALSE;

    printf("Enter a Number \n");
    scanf("%d", &iValue);

    bRet = CheckBit(iValue);

    if(bRet == TRUE)
    {
        printf("4th and 9th bit is ON \n");
    }
    else
    {
        printf("4th and 9th Bit is OFF \n");
    }

    return 0;
}   