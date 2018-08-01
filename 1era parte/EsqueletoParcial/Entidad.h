#ifndef ENTIDAD_H_INCLUDED
#define ENTIDAD_H_INCLUDED

typedef struct
{
    int id;
    int flagOcupado;
    char a[50];
    int b;
}sEntidad1;

#endif // ENTIDAD_H_INCLUDED

int ent1_init(sEntidad1* entidad, int len);
int ent1_alta(sEntidad1* entidad, int len);
int ent1_modificar(sEntidad1* entidad, int len, int id);
int ent1_baja(sEntidad1* entidad, int len, int id);
int ent1_buscarIndicePorDNI(sEntidad1* entidad, int len, char* DNI);
