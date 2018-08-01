#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar Socios y servicios\n2. Anotar Socio a un servicio\n3. Dar de baja un Socio de un servicio\n\n5. Salir\n6. Volver\n"
#define MENU_PPAL_ES2 "\n1. Socios\n2. Servicios\n3. Inscripciones\n4. Informes\n\n5. Salir\n"
#define MENU_PPAL_ES3 "\n1. Listar Socios\n2. Agregar un Socio\n3. Eliminar un Socio\n4. Editar un Socio\n\n5. Salir\n6. Volver\n"
#define MENU_PPAL_ES4 "\n1. Listar servicios\n2. Agregar un servicio\n3. Eliminar un servicio\n4. Editar un servicio\n\n5. Salir\n6. Volver\n"
#define MENU_PPAL_ES5 "\n1. Socios y cantidad de servicios a los que estan inscriptos\n\n2. Salir\n3. Volver\n"
#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"

int vista_init (int idioma);
int vista_mostrarMenu();
int vista_mostrarSocios(ArrayList* pListaSocios);
int vista_mostrarServicios(ArrayList* pListaServicios);
int vista_mostrarSocioServicio(ArrayList* pListaSocServ,  ArrayList* pListaSocio);
int vista_mostrarInforme(ArrayList* pListaSocio);

void vista_mostrarError(char *);

void vista_printIdSocio();
void vista_printIdServicio();
void vista_printIdSocioServicio();

void vista_printErrorSocioServicio();
void vista_printErrorSocioServicio2();








