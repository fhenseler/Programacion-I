#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#define EMPLOYEE_TYPE_ARCHITECT    0
#define EMPLOYEE_TYPE_MANAGER      1
#define EMPLOYEE_TYPE_DESIGNER     2
#define EMPLOYEE_TYPE_JUNIOR       3
#define EMPLOYEE_TYPE_PROGRAMMER   4

struct
{
    int id;
    char name[51];
    char lastName[51];
    int age;
    int type;
}typedef Employee;

int employee_filterEmployee(void* item);
void employee_print(void* pEmployee);
Employee* employee_new(int id, char* name, char* lastName, int age, int type);
void employee_delete(Employee* this);

int employee_setName(Employee*,char* name);
char* employee_getName(Employee*);

int employee_setLastName(Employee*,char* lastName);
char* employee_getLastName(Employee*);

int employee_setId(Employee*,int id);
int employee_getId(Employee*);

int employee_setAge(Employee*,int age);
int employee_getAge(Employee*);

int employee_setType(Employee*,int type);
int employee_getType(Employee*);

#endif // _EMPLOYEE_H



