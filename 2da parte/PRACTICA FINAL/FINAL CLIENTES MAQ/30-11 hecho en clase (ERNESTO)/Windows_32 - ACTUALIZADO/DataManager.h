#ifndef DATAMANAGER_H_INCLUDED
#define DATAMANAGER_H_INCLUDED

//...

#endif // DATAMANAGER_H_INCLUDED

#define ARCHIVO_CLIENTES "clientes.bin"
#define ARCHIVO_ALQUILERES "alquileres.bin"
#define ARCHIVO_CLIENTEALQUILER "clientealquiler.bin"

int dm_saveAll(ArrayList* listaClientes);
int dm_readAll(ArrayList* listaClientes);
int dm_saveAllAlq(ArrayList* listaAlquileres);
int dm_readAllAlq(ArrayList* listaAlquileres);
int dm_saveAllCliAlq(ArrayList* listaClienteAlquiler);
int dm_readAllCliAlq(ArrayList* listaClienteAlquiler);

//int dm_dumpListaClientes(ArrayList* list);
//int parserCliente(FILE* pFile , ArrayList* pArrayListCliente);
