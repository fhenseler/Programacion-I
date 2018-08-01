#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arraylist.h"
#include "Employee.h"

static int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    Employee* pEmployee;
    char var1[50];
    char var2[50];
    char var3[50];
    int var4 = 0;
    int id;
    float salary;
    char name[50];

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);
            id = atoi(var1);
            strcpy(name, var2);
            salary = atof(var3);
            pEmployee = newEmployee(id, name, salary, var4);
            al_add(pArrayListEmployee, pEmployee);
        }
    }
    return 0;
}

int main()
{
    ArrayList* list = al_newArrayList();
    FILE* pFile = fopen("data.csv","r");

    parserEmployee(pFile, list);
    al_sort(list, compareEmployee, 1);
    al_map(list, printEmployee);
    al_map(list, raiseSalary);
    printf("\n\n");
    al_map(list, printEmployee);
    fclose(pFile);
    return 0;
}
