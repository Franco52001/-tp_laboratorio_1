#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedListypedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;t*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char id[50];
    char nombre[128];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee* lista;

    if(pFile == NULL)
        {
            return -1;
        }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    while(!feof(pFile)){
        lista = employee_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        employee_setId(lista,atoi(id));
        employee_setNombre(lista,nombre);
        employee_setHorasTrabajadas(lista,atoi(horasTrabajadas));
        employee_setSueldo(lista,atoi(sueldo));

        ll_add(pArrayListEmployee,lista);
    }


    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* lista;

    if(pFile == NULL)
        {
            return -1;
        }
    do
    {
        lista = employee_new();
        fread(lista,sizeof(Employee),1,pFile);
        ll_add(pArrayListEmployee,lista);
    }while(!feof(pFile));
    return 1;
}
