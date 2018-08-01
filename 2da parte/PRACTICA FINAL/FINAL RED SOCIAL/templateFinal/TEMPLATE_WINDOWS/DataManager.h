#define ARCHIVO_POSTS "Mensajes.csv"
#define ARCHIVO_USUARIOS "Usuarios.csv"
#define ARCHIVO_FEED "feed.csv"

int dm_saveAllPosts(ArrayList* nominaPosts);
int dm_readAllPosts(ArrayList* nominaPosts);

int dm_saveAllUsuarios(ArrayList* nominaUsuarios);
int dm_readAllUsuarios(ArrayList* nominaUsuarios);

int dm_createFeed(ArrayList* nominaPosts, ArrayList* nominaUsuarios);
