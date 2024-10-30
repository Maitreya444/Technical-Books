/*Write a program which accept one number and position from user and check wheather bit at that position is ON or OFF. If bit is 
1 return TRUE otherwise return FALSE

Input : 10  2
Output : TRUE
*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef unsigned int UINT;
typedef int BOOL;

BOOL CheckBit(UINT iNo, UINT iPos)
{
    UINT iMask = 0X00000001;
    UINT iResult = 0;

    iMask = iMask << iPos -1;

    iResult = iMask & iNo;

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

    printf("Enter the bit position you want to check \n");
    scanf("%d", &iBit);

    bRet = CheckBit(iValue, iBit);

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