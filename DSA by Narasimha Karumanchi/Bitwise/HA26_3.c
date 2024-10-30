/*Check 7th, 15th, 21st and 28th bit is ON or OFF*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
typedef unsigned int UINT;

BOOL CheckBit(int iNo)
{
    UINT iMask = 0X08104040;
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
        printf("7th, 15th, 21st and 28th Bit is OFF \n");
    }
    else
    {
        printf("7th, 15th, 21st and 28th Bit is ON \n");
    }

    return 0;
}