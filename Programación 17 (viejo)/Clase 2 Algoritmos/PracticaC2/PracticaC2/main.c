#include <stdio.h>
#include <stdlib.h>

int main()
{
        int num, countNum = 0, sumNum = 0, countEven = 0, countOdd = 0, sumOdd = 0;
        int maxNum, flagMax = 0, minOddNum, flagMin = 0;
        int count3_15 = 0, count16_29 = 0, count30plus = 0;
        char answer = 'y';

        do
        {
            printf("Insert number: ");
            scanf("%d", &num);

                if(num % 2 == 0 && num != 0)
                {
                    countEven++;
                }
                    if(num % 2 != 0 && num != 0)
                    {
                        countOdd++;
                        sumOdd += num;

                        if(flagMin == 0 || num < minOddNum)
                        {
                            minOddNum = num;
                            flagMin = 1;
                        }
                    }
                            if(flagMax == 0 || num > maxNum)
                            {
                                maxNum = num;
                                flagMax = 1;
                            }
                                if(num >= 3 && num <= 15)
                                {
                                    count3_15++;
                                }
                                else
                                {
                                    if(num > 15 && num < 30)
                                    {
                                        count16_29++;
                                    }
                                    else{

                                        if(num >= 30)
                                        {
                                            count30plus++;
                                        }
                                    }
                                }
                                    countNum++;
                                    sumNum += num;
                                    printf("Insert new number? (y/n)\n");
                                    answer = tolower(getch());

        }while(answer == 'y');

            printf("\n1) There are %d even number(s).\n", countEven);
            printf("2) There are %d odd number(s).\n", countOdd);
            printf("3) The sum of all odd numbers is equal to %d\n", sumOdd);
            printf("4) The average of all numbers is equal to %.3f\n", (float) sumNum/countNum);
            printf("5) The max number is %d\n", maxNum);
            printf("6) The min odd number is %d\n", minOddNum);
            printf("7) %d numbers are between 3 and 15\n %d numbers are between 16 and 29\n %d numbers are 30 or higher", count3_15, count16_29, count30plus);


            getch();
            return 0;
}
