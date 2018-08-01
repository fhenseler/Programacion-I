#include <stdio.h>
#include <stdlib.h>

int main()
{
int numPrimo, i, j;

        for(i = 2; i <= 100; i++)
        {

            for(j = 2; j <= i-1; j++)
            {
                numPrimo = i;

                if( i % j == 0 )
                {
                    numPrimo = 0;
                    break;
                }
            }

            if(numPrimo != 0)
            {
                printf("%d\n", numPrimo);
            }


        }

        return 0;
        }
