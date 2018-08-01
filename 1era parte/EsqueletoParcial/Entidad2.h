#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

typedef struct
{
    int id;
    int flagOcupado;
    char a[50];
    int b;
    int idEntidad1;
}sEntidad2;

#endif // ENTIDAD2_H_INCLUDED

int ent2_init(sEntidad2* entidad, int len);
int ent2_generarProximoID(sEntidad2* entidad, int len);
int ent2_buscarIndiceLibre(sEntidad2* entidad, int len);
