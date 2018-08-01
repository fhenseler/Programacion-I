#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"


/** \brief Adds all the filtered employees to a new file
 * \param list ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pFile is NULL pointer] - (0) if Ok
 *
 */
int dm_dumpEmployeeList(ArrayList* list)
{
    FILE *pFile;
    int i=0;
    Employee* employee;
    int retorno = -1;

    pFile = fopen("out.csv","w");

    if(pFile != NULL)
    {
        for(i = 0; i < al_len(list); i++)
        {
            employee = al_get(list, i);
            fprintf(pFile,"%d-%s-%s-%d-%d\n",employee_getId(employee),employee_getName(employee),employee_getLastName(employee),employee_getAge(employee),employee_getType(employee));
        }
            retorno = 0;
    }
    return retorno;
}
