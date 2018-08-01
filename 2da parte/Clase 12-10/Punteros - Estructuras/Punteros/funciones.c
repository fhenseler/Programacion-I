#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

Pixel* pixel_new(int qty)
{
     Pixel* arrayPixeles = NULL;
     arrayPixeles = malloc(sizeof(Pixel) * qty);
     return arrayPixeles;
}

void pixel_delete(Pixel* pPixel)
{
    if(pPixel != NULL)
    {
        free(pPixel);
    }
}
//
//Pixel* pixel_resize(Pixel* pPixel, int newQty)
//{
//    Pixel* pAuxPixel;
//    if(pPixel != NULL)
//    {
//       pAuxPixel = realloc(pPixel, newQty);
//    }
//       return pAuxPixel;
//}

int pixel_setRGB(Pixel* pPixel, int index, int r, int g, int b)
{
    int retorno = -1;

    if(pPixel != NULL && index >= 0)
    {
        retorno = 0;
        (pPixel + index)->r = r;
        (pPixel + index)->g = g;
        (pPixel + index)->b = b; //*(pPixel + index).b
    }
        return retorno;
}

Pixel* pixel_getRGB(Pixel* pPixel, int index)
{
    return (pPixel + index);
}

Pixel pixel_getPixel(Pixel* pPixel, int index)
{
    return *(pPixel + index);
}
