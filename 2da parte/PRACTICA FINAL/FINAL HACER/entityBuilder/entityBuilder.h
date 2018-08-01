typedef struct
{
    char type[256];
    char definition[256];
}Member;

int entity_buildStruct(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildConstructor(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildConstructorPrototype(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildDestructor(char* entityName,char* result);
int entity_buildDestructorPrototype(char* entityName,char* result);
int entity_buildSetters(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildSettersPrototypes(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildGetters(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildGettersPrototypes(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildFinders(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildFindersPrototypes(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildComparativeFunctions(char* entityName, Member* members,int qtyMembers, char* result);
int entity_buildComparativeFunctionsPrototypes(char* entityName, Member* members,int qtyMembers, char* result);
void strToUpper(char *str,char *strUp);
