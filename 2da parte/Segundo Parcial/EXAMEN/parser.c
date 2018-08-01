#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "Validar.h"


/** \brief Reads all the employees from a file, then adds them to the list
 * \param pFile Pointer to File
 * \param pArrayListEmployee ArrayList* Pointer to list
 * \return int Return (-1) if Error [pFile is NULL pointer] - (0) if Ok
 *
 */
int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    Employee* pEmployee;
    char var1[50];
    char var2[50];
    char var3[50];
    char var4[50];
    char var5[50];
    int id;
    int type;
    int age;
    char name[50];
    char lastName[50];

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
//            if(val_validarUnsignedInt(var1)==1)
//            {
               id = atoi(var1);
//            }
//            if(val_validarNombre(var2)==1)
//            {
               strcpy(name, var2);
//            }
//            if(val_validarNombre(var3)==1)
//            {
               strcpy(lastName, var3);
//            }
//            if(val_validarUnsignedInt(var4)==1)
//            {
               age = atoi(var4);
//            }
//            if(val_validarUnsignedInt(var5)==1)
//            {
               type = atoi(var5);
//            }
            pEmployee = employee_new(id, name, lastName, age, type);
            al_add(pArrayListEmployee, pEmployee);
        }
    }
    return 0;
}
