//Write a program which accepts one number from user and off 7th and 10th bit of that number if it is ON. Return modified number.
//INPUT : 79
//OUTPUT : 15

#include<stdio.h>
typedef unsigned int UINT;

UINT ToggleBit(UINT iNo)
{
    UINT iMask = 0X00001111;
    UINT iResult = 0;

    iResult = iNo ^ iMask;

    return iResult;
}

int main()
{
    UINT iValue = 0;
    UINT bRet = 0;

    printf("Enter a Number \n");
    scanf("%d", &iValue);

    bRet = ToggleBit(iValue);

    printf("Number after toggling 7th and 10th bit is : %d\n", bRet);

    return 0;
}