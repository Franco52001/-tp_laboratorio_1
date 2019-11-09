#include "Employee.h"
Employee* employee_new()
{
    return (Employee*)(malloc(sizeof(Employee)));
}

Employee* employee_newParametros(char* id,char* nombre,char*horasTrabajadas)
{
    Employee*  oneEmployee = employee_new();
    if(oneEmployee != NULL)
    {
        oneEmployee->id = atoi(id);
        strcpy(oneEmployee->nombre,nombre);
        oneEmployee->horasTrabajadas = atoi(horasTrabajadas);
    }
    return oneEmployee;
}
int showEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    int i;
    for(i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
        employee_showOneEmployee(pArrayListEmployee,i);
    }
    return 1;
}
int employee_showOneEmployee(LinkedList* pArrayListEmployee,int index)
{
    Employee* aux;
    int id;
    char nombre[51];
    int horas;
    int sueldo;

    aux = (Employee*)ll_get(pArrayListEmployee, index);
    employee_getId(aux, &id);
    employee_getNombre(aux,nombre);
    employee_getSueldo(aux,&sueldo);
    employee_getHorasTrabajadas(aux, &horas);
    printf("%d -- %s -- %d -- %d\n",id,nombre,horas,sueldo);

    return 1;
}

int employee_setId(Employee* this,int id)
{
    int r = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
    }
    return r;
}

int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
    {
        *id = this->id;
    }
    return id;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int r = -1;
    if(this != NULL && nombre > 0)
    {
        strcpy(this->nombre,nombre);
    }
    return r;
}

int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
    }
    return nombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r = -1;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
    }
    return r;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
    }
    return horasTrabajadas;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r = -1;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
    }
    return r;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL)
    {
        *sueldo = this->sueldo;
    }
    return sueldo;
}
void incrementarId(int* id)
{
    *id = id+1;
}

int findEmployeeById(Employee* lista,LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    int retorno = -1;
    printf("\nIngrese numero ID: ");
    scanf("%d",&id);
    if(lista != NULL && ll_len(pArrayListEmployee) > 0)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            lista = ll_get(pArrayListEmployee,i);

            if(employee_getId(lista,&id) == &id)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}

int compararNombre(void* p1, void* p2)
{
    Employee* empleadoUno = (Employee*)p1;
    Employee* empleadoDos = (Employee*)p2;

    return strcmp(empleadoUno->nombre,empleadoDos->nombre);
}

int compararSueldoA(void* p1, void* p2)
{
    Employee* empleadoUno = (Employee*)p1;
    Employee* empleadoDos = (Employee*)p2;

    return(empleadoUno->sueldo > empleadoDos->sueldo);
}

int compararSueldoD(void* p1, void* p2)
{
    Employee* empleadoUno = (Employee*)p1;
    Employee* empleadoDos = (Employee*)p2;

    return(empleadoUno->sueldo < empleadoDos->sueldo);
}

int compararHorasA(void* p1, void* p2)
{
    Employee* empleadoUno = (Employee*)p1;
    Employee* empleadoDos = (Employee*)p2;

    return(empleadoUno->horasTrabajadas > empleadoDos->horasTrabajadas);
}

int compararHorasD(void* p1, void* p2)
{
    Employee* empleadoUno = (Employee*)p1;
    Employee* empleadoDos = (Employee*)p2;

    return(empleadoUno->horasTrabajadas < empleadoDos->horasTrabajadas);
}
