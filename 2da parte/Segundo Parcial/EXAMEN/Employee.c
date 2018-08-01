#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


Employee* employee_new(int id, char* name, char* lastName, int age, int type)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->age = age;
        pEmployee->type = type;
        returnAux = pEmployee;
    }

    return returnAux;
}

void employee_delete(Employee* this)
{
    free(this);
}

void employee_print(void* pEmployee)
{
    Employee* employee = (Employee*)pEmployee;
    printf("ID:%d Nombre:%s Apellido:%s Edad:%d Tipo:%d\r\n",employee_getId(employee),employee_getName(employee),employee_getLastName(employee),employee_getAge(employee),employee_getType(employee));
}

int employee_filterEmployee(void* item)
{
    int retorno = 0;

    Employee* auxEmployee = (Employee*)item;

    if(auxEmployee->age > 30 && auxEmployee->type == 4)
    {
        retorno = 1;
    }

    return retorno;
}


int employee_setName(Employee* this,char* name)
{
    strcpy(this->name,name);
    return 0;
}


char* employee_getName(Employee* this)
{
    return this->name;
}

int employee_setLastName(Employee* this,char* lastName)
{
    strcpy(this->lastName,lastName);
    return 0;
}


char* employee_getLastName(Employee* this)
{
    return this->lastName;
}

int employee_setId(Employee* this,int id)
{
    this->id = id;
    return 0;
}


int employee_getId(Employee* this)
{
    return this->id;
}

int employee_setAge(Employee* this,int age)
{
    this->age = age;
    return 0;
}


int employee_getAge(Employee* this)
{
    return this->age;
}

int employee_setType(Employee* this,int type)
{
    this->type = type;
    return 0;
}


int employee_getType(Employee* this)
{
    return this->type;
}


