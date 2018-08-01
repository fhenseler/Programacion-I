#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"


int main()
{
	alumno alumnitos[A];
	char seguir='s';
	char guardar= 's';
	int i;

		for( i=0; i<A; i++)
		alumnitos[i].legajo=0;

	if(cargarDesdeArchivo(alumnitos))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");


	system("cls");
	do
	{
		switch(menu())
		{
			case '1':
				system("cls");
				alta(alumnitos);
				break;
			case '2':
				system("cls");
				listar(alumnitos);
				break;
			case '3':
				system("cls");
				baja(alumnitos);
				break;
			case '4':
				system("cls");
				modificar(alumnitos);
				break;
			case '5':
				system("cls");
				mayorPromedio(alumnitos);
				break;
			case '6':
                system("cls");
                crearTxt(alumnitos);
                break;
			case '7':

				printf("\nGuardar cambios S/N ?: ");
				guardar = tolower(getche());

				if(guardar == 's')
				{
					if(guardarEnArchivo(alumnitos))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}

				seguir='n';
				break;

		}
	}while(seguir=='s');
	printf("\n");
	system("pause");
}


