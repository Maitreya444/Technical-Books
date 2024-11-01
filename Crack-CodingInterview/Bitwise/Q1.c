/*You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M starts 
at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011,
you can assume that there are at least 5 bits between j and i. You would not, for eg : have j = 3 and i = 2, because M could not
fully fit between bit 3 and bit 2. 

eg : 
Input: N = 10000000000, M = 1011, i = 2, j = 6
Output: N = 10001001100

*/

#include<stdio.h>
typedef unsigned int UINT;

UINT ModifyBits(UINT iNo1, UINT iNo2, UINT iPos1, UINT iPos2)
{
    UINT iDigit = 0;
    int iCnt = 0;
    UINT temp = iNo2;

    while(temp !=0)
    {
        iDigit = temp % 2;
        iCnt++;
        temp = temp / 2;
    }

    if(iCnt > (iPos2 - iPos1) +1)
    {
        printf("Invalid bit position \n");
        return -1;
    }

    else
    {   
        UINT iMask1 = ~0;                   // Sets all F
        UINT left = iMask1 << (iPos2+1);    // Shits iPos2 bits to left. eg iPos2 = 7 then 8 bits of (1's) will shift to left.
        UINT right = (1 << iPos1) -1;       // Shifts (1's) to right by iPos1 bits. eg iPos1 = 2 i.e 2^3 then it will do (1's) from right 

        UINT iMask2 = left | right;         // Bitwise OR kela 

        UINT iNo1_clear = iNo1 & iMask2;    // Bitwise AND kela ani bits clear kele
        UINT iNo2_shift = iNo2 << iPos1;    // Shift kela iNo2 at iPos1

        return iNo1_clear | iNo2_shift;     // Combine kela
    }
}

int main()
{
    UINT iValue1 = 0;
    UINT iValue2 = 0;
    UINT iPosition1 = 0;
    UINT iPosition2 = 0;
    int iRet = 0;

    printf("Enter a number 1\n");
    scanf("%d", &iValue1);

    printf("Enter a number 2\n");
    scanf("%d", &iValue2);

    printf("Enter a position from where you want to start \n");
    scanf("%d", &iPosition1);

    printf("Enter a position from where you want to end \n");
    scanf("%d", &iPosition2);

    iRet = ModifyBits(iValue1, iValue2, iPosition1, iPosition2);

    printf("Number after modifying is : %d\n", iRet);

    return 0;
}