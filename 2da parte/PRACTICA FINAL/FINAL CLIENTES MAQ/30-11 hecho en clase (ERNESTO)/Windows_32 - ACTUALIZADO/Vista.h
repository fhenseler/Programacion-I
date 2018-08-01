#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar Clientes y Alquileres\n2. Anotar Cliente a un Alquiler\n3. Dar de baja un Cliente de un Alquiler\n\n5. Salir\n6. Volver\n"
#define MENU_PPAL_ES2 "\n1. Clientes\n2. Alquileres\n3. Inscripciones\n4. Informes\n\n5. Salir\n"
#define MENU_PPAL_ES3 "\n1. Listar Clientes\n2. Agregar un Cliente\n3. Eliminar un Cliente\n4. Editar un Cliente\n\n5. Salir\n6. Volver\n"
#define MENU_PPAL_ES4 "\n1. Listar Alquileres\n2. Agregar un Alquiler\n3. Eliminar un Alquiler\n4. Editar un Alquiler\n\n5. Salir\n6. Volver\n"
#define MENU_PPAL_ES5 "\n1. Clientes y cantidad de es a los que estan inscriptos\n\n2. Salir\n3. Volver\n"
#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"

int vista_init (int idioma);
int vista_mostrarMenu();
int vista_mostrarClientes(ArrayList* pListaClientes);
int vista_mostrarAlquileres(ArrayList* pListaAlquileres);
int vista_mostrarClienteAlquiler(ArrayList* pListaCliAlq,  ArrayList* pListaCliente);
int vista_mostrarInforme(ArrayList* pListaCliente);

void vista_mostrarError(char *);

void vista_printIdCliente();
void vista_printIdAlquiler();
void vista_printIdClienteAlquiler();

void vista_printErrorClienteAlquiler();
void vista_printErrorClienteAlquiler2();








