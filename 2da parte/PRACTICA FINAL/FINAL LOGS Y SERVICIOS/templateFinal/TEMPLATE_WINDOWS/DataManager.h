#define ARCHIVO_LOGS "logs.txt"
#define ARCHIVO_SERVICIOS "servicios.txt"

int dm_saveAllLogs(ArrayList* pArrayLogs);
int dm_readAllLogs(ArrayList* pArrayLogs);

int dm_saveAllServicios(ArrayList* pArrayServicios);
int dm_readAllServicios(ArrayList* pArrayServicios);

int dm_saveAllLogsG3(ArrayList* pArrayLogs);
int dm_saveAllLogsGM7(ArrayList* pArrayLogs);
