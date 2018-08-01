#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{
    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
        return 0;
}

void printEmployee(void* pEmployee)
{
    Employee* employee = (Employee*)pEmployee;
    printf("Nombre:%s Salario:%.2f\r\n",emp_getName(employee),emp_getSalary(employee));
}

void raiseSalary(void* pEmployee)
{
    Employee* e = (Employee*)pEmployee;
    float salary;
    salary = emp_getSalary(e) * 2;
    emp_setSalary(e, salary);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],float salary, int isEmpty)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        pEmployee->salary = salary;
        pEmployee->isEmpty = isEmpty;
        returnAux = pEmployee;
    }

    return returnAux;

}


int emp_delete(Employee* this)
{
    free(this);
    return 0;
}


int emp_setName(Employee* this,char* name)
{
    strcpy(this->name,name);
    return 0;
}


char* emp_getName(Employee* this)
{
    return this->name;
}

int emp_setId(Employee* this,int id)
{
    this->id = id;
    return 0;
}


int emp_getId(Employee* this)
{
    return this->id;
}

int emp_setIsEmpty(Employee* this,int isEmpty)
{
    this->isEmpty = isEmpty;
    return 0;
}


int emp_getIsEmpty(Employee* this)
{
    return this->isEmpty;
}

int emp_setSalary(Employee* this,float salary)
{
    this->salary = salary;
    return 0;
}


float emp_getSalary(Employee* this)
{
    return this->salary;
}
