#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define LENGTH 20

typedef struct
{
    char name[30];
    unsigned int age;
    unsigned int id;
    int status; //Activo (1) o Inactivo (0)

}SPerson;

void showMenu(void);

int getValidInt(char[], char[], int);
int validateRangeInt(int, char[], int, int);

void getString(char[], char[]);
int itsAlpha(char[]);
void getStringAlpha(char[], char[], int);
void validateRangeStr(char[], char[], int);

void setStatus(SPerson[], int, int);

int addPerson(SPerson[], int);
int removePerson(SPerson[], int);

void sortPeopleArray(SPerson[], int);
void showPeopleArray(SPerson[], int);

int findEmptyPlace(SPerson[], int);
int findPersonById(SPerson[], int, int);

void printGraph(SPerson[], int);

#endif // FUNCIONES_H_INCLUDED
