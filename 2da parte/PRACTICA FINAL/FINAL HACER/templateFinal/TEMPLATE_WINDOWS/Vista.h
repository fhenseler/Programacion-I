#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar Usuarios Ordenados por Nombre\n2. Listar Usuarios Ordenados por Nacionalidad y Nombre \n3. Listar Temas \n4. Escuchar Tema\n5. Guardar Estadistica\n6. Tema mas escuchado\n7. Tema mas escuchado segun nacionalidad del usuario\n8. Autor con mas reproducciones\n9. Autor con mas temas\n10. Salir\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"


int vista_init (int idioma);
int vista_mostrarMenu();
void mostrarError(char * mensaje);
void vista_mostrarUsuario(ArrayList* pListaUsuarios);
void vista_mostrarTemas(ArrayList* pListaTemas);



