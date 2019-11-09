#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();
int showEmployee(LinkedList* pArrayListEmployee);
int showOneEmployee(LinkedList* pArrayListEmployee,int index);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
void incrementarId(int* id);
int findEmployeeById(Employee* lista,LinkedList* pArrayListEmployee);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int compararNombre(void* p1, void* p2);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int compararHorasA(void* p1, void* p2);
int compararHorasD(void* p1, void* p2);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int compararSueldoA(void* p1, void* p2);
int compararSueldoD(void* p1, void* p2);


#endif // employee_H_INCLUDED
