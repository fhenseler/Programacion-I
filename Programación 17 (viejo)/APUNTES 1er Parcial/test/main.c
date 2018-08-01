#include <stdio.h>
struct alumno {
char nombre[20];
int nota;
};
void main(void)
{
struct alumno alu1 , alu2;
printf("Ingrese nombre");
gets(alu1.nombre);
printf("Ingrese nota");
scanf("%d",&alu1.nota);
alu2=alu1;
}


struct alumno alu[20];
for(i=0;i<20;i++)
{
printf("Ingrese nombre: ");
gets(alu[i].nombre);
printf("Ingrese nota: ");
scanf("%d",&alu[i].nota);
fflush(stdin);
}
// ...
}
