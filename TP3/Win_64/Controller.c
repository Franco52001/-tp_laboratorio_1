#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    parser_EmployeeFromText(pFile,pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bi (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path,"rb");
    parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    Employee* empleado;
    Employee* auxEmpleado;
    int id = 0;
    int horas;
    int sueldo;
    char nombre[51];
    int length;

    length = ll_len(pArrayListEmployee);
    empleado = employee_new();
    auxEmpleado = (Employee*)ll_get(pArrayListEmployee,length - 1);

    id = employee_getId(auxEmpleado,&id);
    employee_setId(empleado,id + 1);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    employee_setNombre(empleado,nombre);
    printf("Ingrese horas trabajadas: ");
    scanf("%d",&horas);
    employee_setHorasTrabajadas(empleado,&horas);
    printf("Ingrese sueldo: ");
    scanf("%d",&sueldo);
    employee_setSueldo(empleado,&sueldo);

    ll_add(pArrayListEmployee,empleado);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int index;
    int mod;
    int retorno = -1;
    int length;
    int horas;
    int sueldo;
    char nombre[51];
    length = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL && length > 0)
    {
        showEmployee(pArrayListEmployee);
        index = findEmployeeById(empleado,pArrayListEmployee);
        if(index != -1)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee,index);
            while(mod !=4)
            {
                printf("\nQue desea modificar?\n1.Nombre\n2.Horas Trabajadas\n3.Salario\n4.Terminar ");
                scanf("%d",&mod);
                switch(mod)
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    employee_setNombre(empleado,nombre);
                    employee_showOneEmployee(empleado,index);
                    break;
                case 2:
                    printf("\nIngrese nuevas horas trabajadas: ");
                    scanf("%d",&horas);
                    employee_setHorasTrabajadas(empleado,horas);
                    employee_showOneEmployee(empleado,index);
                    break;
                case 3:
                    printf("\nIngrese nuevo salario: ");
                    scanf("%d",&sueldo);
                    employee_setSueldo(empleado,sueldo);
                    employee_showOneEmployee(empleado,index);
                    break;
                case 4:
                    break;
                default:
                    printf("Opcion no valida\n");
                    break;
                }
            }
        }
    }
    else
    {
        printf("No existe una lista\n");
    }
    return retorno;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int index;
    int remove;
    int retorno = -1;
    int length;
    length = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL && length > 0)
    {
        showEmployee(pArrayListEmployee);
        index = findEmployeeById(empleado,pArrayListEmployee);
        if(index != -1)
        {
            printf("\nEsta seguro que desea eliminar los siguientes datos?: ");
            employee_showOneEmployee(empleado,index);
            printf("\n1.Si\n2.No\n");
            scanf("%d",&remove);
            if(remove == 1)
            {
                ll_remove(pArrayListEmployee,index);
                printf("\nDatos eliminados\n");
                showEmployee(pArrayListEmployee);
            }
            else if(remove == 2)
            {
                printf("\nAccion cancelada\n");
                showEmployee(pArrayListEmployee);
            }
            else
            {
                printf("Opcion no valida,Ingrese nuevamente");
                scanf("%d",&remove);
            }
        }
        else
        {
            printf("\nDatos no encontardos\n");
        }
    }
    else
    {
        printf("No existe una lista\n");
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    showEmployee(pArrayListEmployee);
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int order;
    int sort;
    int length;
    length = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL && length > 0)
    {
        showEmployee(pArrayListEmployee);
        while(order !=3)
        {
            printf("\nComo desear ordenar?\n1.Ascendente\n2.Descendente\n3.Terminar\n");
            scanf("%d",&order);
            switch(order)
            {
            case 1:
                while(sort !=4)
                {
                    printf("\nPor que desear ordenar?\n1.Por Nombre\n2.Por Horas Trabajadas\n3.Por Sueldo\n4.Terminar\n");
                    scanf("%d",&sort);
                    switch(sort)
                    {
                    case 1:
                        ll_sort(pArrayListEmployee,compararNombre,1);
                        showEmployee(pArrayListEmployee);
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,compararHorasA,1);
                        showEmployee(pArrayListEmployee);
                        break;
                    case 3:
                        ll_sort(pArrayListEmployee,compararSueldoA,1);
                        showEmployee(pArrayListEmployee);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Opcion no valida\n");
                        break;
                    }
                }
                break;
            case 2:
                while(sort !=4)
                {
                    printf("\nPor que desear ordenar?\n1.Por Nombre\n2.Por Horas Trabajadas\n3.Por Sueldo\n4.Terminar\n");
                    scanf("%d",&sort);
                    switch(sort)
                    {
                    case 1:
                        ll_sort(pArrayListEmployee,compararNombre,0);
                        showEmployee(pArrayListEmployee);
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,compararHorasD,1);
                        showEmployee(pArrayListEmployee);
                        break;
                    case 3:
                        ll_sort(pArrayListEmployee,compararSueldoD,1);
                        showEmployee(pArrayListEmployee);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Opcion no valida\n");
                        break;
                    }
                }
                break;
            case 3:
                break;
            default:
                printf("Opcion no valida\n");
                break;
            }
        }
    }
    else
    {
        printf("No existe una lista\n");
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int i;
    int id;
    char nombre;
    int horas;
    int sueldo;
    Employee* lista;
    pFile = fopen(path,"w");
    for(i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(lista,&id);
        employee_getNombre(lista,nombre);
        employee_getHorasTrabajadas(lista,&horas);
        employee_getSueldo(lista,&sueldo);

        fprintf(pFile,"%d -- %s -- %d -- %d\n",id,nombre,horas,sueldo);

    }
    fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    int i;
    Employee* lista;
    pFile = fopen(path,"w");
    for(i = 0; i < ll_len(pArrayListEmployee); i++)
    {
       lista = (Employee*)ll_get(pArrayListEmployee,i);
       fwrite(lista,sizeof(Employee),1,pFile);

    }
    fclose(pFile);
    return 1;
}

