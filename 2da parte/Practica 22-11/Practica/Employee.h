/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    int id;
    char name[51];
    float salary;
    int isEmpty;

}typedef Employee;
#endif // __EMPLOYEE

int compareEmployee(void* pEmployeeA,void* pEmployeeB);
void printEmployee(void* pEmployee);
void raiseSalary(void* pEmployee);
Employee* newEmployee(int id, char name[],float salary, int isEmpty);

int emp_setName(Employee*,char* name);
char* emp_getName(Employee*);

int emp_setId(Employee*,int id);
int emp_getId(Employee*);

int emp_setIsEmpty(Employee*,int isEmpty);
int emp_getIsEmpty(Employee*);

int emp_setSalary(Employee*,float salary);
float emp_getSalary(Employee*);

