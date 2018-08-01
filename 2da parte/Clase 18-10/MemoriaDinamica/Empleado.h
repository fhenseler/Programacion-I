#ifndef __EMPLEADO
#define __EMPLEADO
#define NAME_LENGTH 51
#define LASTNAME_LENGTH 51
#define DEBUG_MODE 1

typedef struct
{
    char nombre[NAME_LENGTH];
    char apellido[LASTNAME_LENGTH];
    int idSector;
}Empleado;

#endif // __EMPLEADO

Empleado* empleado_new();
Empleado* empleado_newConstructor(char *nombre, char *apellido, int idSector);
void empleado_delete(Empleado* pEmpleado);

int empleado_setNombre(Empleado* pEmpleado, char *nombre); //VALIDACIONES ACA
char* empleado_getNombre(Empleado* pEmpleado);

int empleado_setApellido(Empleado* pEmpleado, char *apellido);
char* empleado_getApellido(Empleado* pEmpleado);

int empleado_setIdSector(Empleado* pEmpleado, int idSector);
int empleado_getIdSector(Empleado* pEmpleado);

void empleado_debugPrint(Empleado* pEmpleado);
