/*Write a program which accept 1 number from user and count number of ON (1) bits in it without using % and / operator 

INPUT : 10
OUTPUT : 3

*/

#include<stdio.h>
typedef unsigned int UINT;

UINT CountOne(UINT iNo)
{
    UINT iMask = 0X00000001;
    UINT iCount = 0;

    //We will right shift the bits and compare

    while(iNo)
    {
        iCount = iCount + (iNo & iMask);
        iNo >>= 1;
    }
    return iCount;
}

int main()
{
    UINT iValue = 0;
    UINT iRet = 0;

    printf("Enter a Number \n");
    scanf("%d", &iValue);

    iRet = CountOne(iValue);

    printf("Count of 1bit's are : %d\n", iRet);

    return 0;
}