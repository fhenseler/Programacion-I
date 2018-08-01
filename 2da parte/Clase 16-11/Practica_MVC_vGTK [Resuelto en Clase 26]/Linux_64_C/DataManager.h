
#define ARCHIVO_SOCIOS "socios.bin"
#define ARCHIVO_SERVICIOS "servicios.bin"
#define ARCHIVO_SOCIOSERVICIO "socioservicio.bin"

int dm_saveAll(ArrayList* listaSocios);
int dm_readAll(ArrayList* listaSocios);
int dm_saveAllServ(ArrayList* listaServicios);
int dm_readAllServ(ArrayList* listaServicios);
int dm_saveAllSocServ(ArrayList* listaSocioServicio);
int dm_readAllSocServ(ArrayList* listaSocioServicio);
