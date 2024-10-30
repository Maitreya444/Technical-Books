/*Write a program which accept one number and position from that user and ON that bit. Return the modified bit

Input : 10  2
Output : 8

*/

#include<stdio.h>
typedef int BOOL;
typedef unsigned int UINT;

UINT ToggleBit(UINT iNo, UINT iPos)
{
    UINT iMask = 0X00000001;
    UINT iResult = 0;

    iMask = iMask << iPos-1;

    iResult = iNo | iMask;

    return iResult;
}

int main()
{
    UINT iValue = 0;
    UINT iBit = 0;
    UINT iRet = 0;

    printf("Enter a Number \n");
    scanf("%d", &iValue);

    printf("Enter the bit position you want to check \n");
    scanf("%d", &iBit);

    iRet = ToggleBit(iValue, iBit);

    printf("Modified number after toggling bit is : %d\n", iRet);
    
    return 0;
}   