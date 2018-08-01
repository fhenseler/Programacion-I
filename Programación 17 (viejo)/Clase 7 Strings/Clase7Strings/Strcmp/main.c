#include <stdio.h>
#include <stdlib.h>

int main()
{
     char nombre[30] = {"A"};
     char nombre2[30] = {"a"};
     int ret;

     ret = strcmp(nombre, nombre2);
     printf("%d", ret);


}
