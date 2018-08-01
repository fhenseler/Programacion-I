#ifndef DATAMANAGER_H_INCLUDED
#define DATAMANAGER_H_INCLUDED

//...

#endif // DATAMANAGER_H_INCLUDED

#define ARCHIVO_SocioS "Socios.bin"
#define ARCHIVO_SERVICIOS "servicios.bin"
#define ARCHIVO_SocioSERVICIO "Socioservicio.bin"

int dm_saveAll(ArrayList* listaSocios);
int dm_readAll(ArrayList* listaSocios);
int dm_saveAllServ(ArrayList* listaServicios);
int dm_readAllServ(ArrayList* listaServicios);
int dm_saveAllSocServ(ArrayList* listaSocioServicio);
int dm_readAllSocServ(ArrayList* listaSocioServicio);

int dm_dumpListaSocios(ArrayList* list);
int parserSocio(FILE* pFile , ArrayList* pArrayListSocio);
