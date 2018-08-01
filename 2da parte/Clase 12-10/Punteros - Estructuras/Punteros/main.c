#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    Pixel *pPixel;
    Pixel *pAuxiliarPixel;
    Pixel auxiliarPixel;

    pPixel = pixel_new(100);

    if(pixel_setRGB(pPixel, 10, 255, 255, 255) == -1)
    {
        printf("ERROR!");
    }

    pAuxiliarPixel = pixel_getRGB(pPixel, 10);
    if(pAuxiliarPixel == NULL)
    {
        printf("\nERROR!");
    }
    printf("RED: %d - GREEN: %d - BLUE: %d", pAuxiliarPixel->r, pAuxiliarPixel->g, pAuxiliarPixel->b);

    pixel_setRgb(pPixel,10,200,255,255);
    auxiliarPixel = pixel_getPixel(pPixel, 10);
    printf("\nRED: %d - GREEN: %d - BLUE: %d", auxiliarPixel.r, auxiliarPixel.g, auxiliarPixel.b);

    return 0;
}
