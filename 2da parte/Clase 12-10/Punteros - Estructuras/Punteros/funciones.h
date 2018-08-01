#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//...

#endif // FUNCIONES_H_INCLUDED

typedef struct
{
    int r;
    int g;
    int b;
}Pixel;

int pixel_setRGB(Pixel* pPixel, int index, int r, int g, int b);
Pixel* pixel_getRGB(Pixel* pPixel, int index);
Pixel* pixel_new(int qty);//Devolver posicion de memoria donde empieza el array
Pixel pixel_getPixel(Pixel* pPixel, int index);
void pixel_delete(Pixel* pPixel);
//Pixel* pixel_resize(Pixel* pPixel, int newQty);
