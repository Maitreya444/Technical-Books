/*Check 5th and 18th bit is ON or OFF*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
typedef unsigned int UINT;

BOOL CheckBit(int iNo)
{
    UINT iMask = 0X00020010;
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

    if(bRet == FALSE)
    {
        printf("5th and 18th Bit is OFF \n");
    }
    else
    {
        printf("5th and 18th Bit is ON \n");
    }

    return 0;
}