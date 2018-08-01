#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define C 3


int menu(char[]);


int main()
{
    int codigo[C];
    int auxInt;
    float precio[C];
    float auxFloat;
    char descripcion[C][31];
    char auxString[100];
    int opcion;
    int i;
    int j;
    float maxPrecio;
    int flag=0;
    do
    {
      opcion=menu("1.Cargar\n2.Ordenar\n3.Mayor\n4.Salir\nElija una opcion");
      switch(opcion)
      {
        case 1:
            printf("\nCarga");
            for(i=0; i<C; i++)
            {
                printf("Ingrese Codigo: ");
                scanf("%d", &codigo[i]);
                printf("Ingrese Precio: ");
                scanf("%f", &precio[i]);
                printf("Ingrese descripcion: ");
                fflush(stdin);
                gets(descripcion[i]);
            }



        break;
        case 2:
            printf("\nOrdena");

            for(i=0; i<C-1; i++)
            {
                for(j=i+1; j<C; j++)
                {
                   if(strcmp(descripcion[i], descripcion[j])>0)
                   {
                        strcpy(auxString, descripcion[i]);
                        strcpy(descripcion[i], descripcion[j]);
                        strcpy(descripcion[j], auxString);

                        auxInt=codigo[i];
                        codigo[i]=codigo[j];
                        codigo[j]=auxInt;


                         auxFloat=precio[i];
                        precio[i]=precio[j];
                        precio[j]=auxFloat;



                    }
                    else if(strcmp(descripcion[i], descripcion[j])==0)
                    {
                        if(codigo[i]>codigo[j])
                        {
                            auxInt=codigo[i];
                            codigo[i]=codigo[j];
                            codigo[j]=auxInt;


                            auxFloat=precio[i];
                            precio[i]=precio[j];
                            precio[j]=auxFloat;
                        }
                    }

                }
            }


            for(i=0; i<C; i++)
            {
                printf("%d--%.2f--%s\n", codigo[i], precio[i], descripcion[i] );
            }
        break;
        case 3:
            printf("\nMayor");

            for(i=0; i<C; i++)
            {
                if(flag==0 || precio[i]>maxPrecio)
                {
                    maxPrecio=precio[i];
                    flag=1;

                }
            }

           printf("El maximo precio fue: %f", maxPrecio);
            for(i=0; i<C; i++)
            {
                if(precio[i]==maxPrecio)
                {
                    printf("%d--%s\n", codigo[i], descripcion[i]);
                }
            }





        break;
      }




    }while(opcion!=4);






    return 0;
}
int menu(char texto[])
{
    int opcion;
    printf("%s", texto);
    scanf("%d", &opcion);
    return opcion;
}
