#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

//...

#endif // VALIDAR_H_INCLUDED

void myFgets(char* buffer, int limite, FILE* archivo);

int val_getNombre(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int val_getDescripcion(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int val_getFloat(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int val_getUnsignedInt(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int val_getDNI(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int val_validarNombre(char* buffer);
int val_validarDescripcion(char* buffer);
int val_validarFloat(char* buffer);
int val_validarUnsignedInt(char* buffer);
int val_validarRangoInt(char* buffer, char* errorMessage, int lowLim, int hiLim);
int val_validarDNI(char* buffer);
int val_validarRangoDNI(char* buffer, char* errorMessage, int len);
int val_getNombreArchivo(char* destino, char* mensaje, char* mensajeError, int intentos, int limite);
int val_validarNombreArchivo(char* buffer);
int val_checkDNI(char* buffer);
