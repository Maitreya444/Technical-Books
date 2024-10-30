//Write a program which accepts one number from user and off 7th and 10th bit of that number if it is ON. Return modified number.
//INPUT : 79
//OUTPUT : 15

#include<stdio.h>
typedef unsigned int UINT;

UINT ToggleBit(UINT iNo)
{
    UINT iMask1 = 0X00000001;
    UINT iMask2 = 0X00000001;
    UINT iMask = 0X00000000;
    UINT iResult = 0;

    iMask1 = iMask1 << 7-1;
    iMask2 = iMask2 << 10-1;

    iMask = iMask1 | iMask2;

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

    printf("Number after toggling 7th and 10th bit if it was ON is : %d\n", bRet);

    return 0;
}