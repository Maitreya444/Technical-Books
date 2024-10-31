/*Write a program which accept 2 numbers from user and display position of common ON bits from that 2 numbers 

Input : 10  15          (1010)  (1111)
Output : 2  4   */

#include<stdio.h>
typedef unsigned int UINT;
#define TRUE 1
#define FALSE 0

void CommonBits(UINT iNo1, UINT iNo2)
{
    UINT iMask = 0X00000001;
    UINT iPos = 1;

    while(iNo1 !=0 || iNo2 !=0)
    {
        if((iNo1 & iMask) && (iNo2 & iMask))
        {
            printf("%d ", iPos);
        }
        iPos++;
        iNo1 = iNo1 >>1;
        iNo2 = iNo2 >>1;
    }
    printf("\n");
}

int main()
{
    UINT iValue1 = 0, iValue2 = 0;    

    printf("Enter number 1 \n");
    scanf("%d", &iValue1);

    printf("Enter number 2 \n");
    scanf("%d", &iValue2);

    CommonBits(iValue1, iValue2);

    return 0;
}