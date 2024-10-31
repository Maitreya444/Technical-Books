//Check 9th and 12th bit is ON or OFF

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef unsigned int UINT;
typedef int BOOL;

BOOL CheckBit(UINT iNo)
{
    UINT iMask = 0X00000900;
    UINT iResult = 0;

    iResult = iMask & iNo;

    if(iResult == iNo)
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
        printf("TRUE \n");
    }
    else
    {
        printf("FALSE \n");
    }

    return 0;
}