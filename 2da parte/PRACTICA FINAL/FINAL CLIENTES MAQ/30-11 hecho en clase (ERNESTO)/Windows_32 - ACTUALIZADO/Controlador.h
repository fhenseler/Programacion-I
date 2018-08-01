
void cont_init();

int cont_altaCliente(char* nombre,char* apellido,char* dni);
int cont_bajaCliente(int);
int cont_modificarCliente(char* nombre,char* apellido,char* dni, int id, int estado);
int cont_listarClientes();
int cont_checkCliente(int id);
int cont_checkClienteByDni(char* dni);

int cont_altaAlquiler(char* descripcion);
int cont_bajaAlquiler(int);
int cont_modificarAlquiler(char* descripcion, int id, int estado);
int cont_listarAlquileres();
int cont_checkAlquiler(int id);

int cont_altaClienteAlquiler(int idCliente, int idAlquiler);
int cont_bajaClienteAlquiler(int);
int cont_listarClienteAlquiler();
int cont_checkClienteAlquiler(int id);

int cont_listarInforme();
