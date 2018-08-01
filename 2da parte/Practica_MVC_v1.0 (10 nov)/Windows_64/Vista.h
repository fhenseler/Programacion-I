#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n*** SOCIOS ***\n\n1. Listar Socios\n2. Agregar un socio\n3. Eliminar un socio\n4. Editar un socio\n\n*** SERVICIOS ***\n\n5. Listar servicios\n6. Agregar un servicio\n7. Eliminar un servicio\n8. Editar un servicio\n\n\n9. Salir\n"
#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"



int vista_init (int idioma);
int vista_mostrarMenu();
void vista_mostrarSocios(ArrayList* pListaSocios);
void vista_mostrarServicios(ArrayList* pListaServicios);
void vista_mostrarError(char *);

void vista_printIdSocio();





