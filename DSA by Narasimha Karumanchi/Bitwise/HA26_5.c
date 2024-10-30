//Check weahther 1st or last(32) bit is ON or OFF

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef unsigned int UINT;
typedef int BOOL;

BOOL CheckBit(UINT iNo)
{
    UINT iResult = 0;
    UINT iMask = 0X80000001;

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

    printf("Enter a number \n");
    scanf("%d", &iValue);

    bRet = CheckBit(iValue);

    if(bRet == TRUE)
    {
        printf("1st and 32nd bit is ON \n");
    }
    else
    {
        printf("1st and 32nd bit is OFF \n");
    }

    return 0;
}