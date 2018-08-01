#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Leer Logs y Servicios\n2. Listar Logs\n3. Procesar Informacion\n4. Mostrar Estadisticas\n5. Salir\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"


int vista_init (int idioma);
int vista_mostrarMenu();
void mostrarError(char * mensaje);
void vista_mostrarLogs(ArrayList* nominaLogs);



