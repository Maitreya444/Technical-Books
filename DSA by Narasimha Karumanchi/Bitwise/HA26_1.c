/*Check 15th bit is ON or OFF*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
typedef unsigned int UINT;

BOOL CheckBit(int iNo)
{
    UINT iMask = 0X00004000;
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
        printf("Bit is OFF \n");
    }
    else
    {
        printf("Bit is ON \n");
    }

    return 0;
}