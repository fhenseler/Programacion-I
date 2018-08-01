#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char name[31];
    int age;
    long int id;
    int stateFlag;
}SPerson;

//funciones.c (Funciones propias del TP2)
int menu();
void initializeArray(SPerson APerson[], int LEN);
int getFreeSpace(SPerson APerson[], int LEN);
int idSearch(SPerson APerson[], int auxId, int LEN);
void addPerson(SPerson APerson[], int LEN);
void removePerson(SPerson APerson[], int LEN);
void sortByName(SPerson APerson[], int LEN);
void printList(SPerson APerson[], int LEN);
void printGraph(SPerson APerson[], int LEN);


//funciones2.c (Funciones útiles traídas de afuera)
void getString(char message[],char input[]);
int getStringLetras(char message[],char input[]);
int getStringNumeros(char message[],char input[]);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int getInt(char mensaje[]);

#endif //FUNCIONES_H_INCLUDED
