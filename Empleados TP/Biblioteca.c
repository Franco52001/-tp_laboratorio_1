#include "Biblioteca.h"

int initEmployees(sEmployee* list,int length)
{
    int i;
    int retorno = -1;
    if(list != NULL && length > 0)
    {
        for(i = 0; i < length; i++)
        {
            list[i].isEmpty = FALSE;
        }
        retorno = 0;
    }
    return retorno;
}
int searchFree(sEmployee* list,int length)
{
    int i;
    int index = -1;
    for(i = 0; i < length; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            index = i;
            break;
        }
    }
    return index;
}

void printEmployee(sEmployee oneEmployee)
{
    printf("%04d\t%02d\t%20s\t%20s\t%10f\n",oneEmployee.id,oneEmployee.sector,oneEmployee.name,oneEmployee.lastName,oneEmployee.salary);
}
sEmployee addEmployee()
{
    sEmployee myEmployee;
    printf("Ingrese sector: ");
    scanf("%d",&myEmployee.sector);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(myEmployee.name);
    toLowerCase(myEmployee.name);
    firstLetterToUpperCase(myEmployee.name);
    while(onlyLetters(myEmployee.name) == -1)
    {
        printf("Ingrese nombre nuevamente: ");
        fflush(stdin);
        gets(myEmployee.name);
    }

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(myEmployee.lastName);
    toLowerCase(myEmployee.lastName);
    firstLetterToUpperCase(myEmployee.lastName);
    while(onlyLetters(myEmployee.lastName) == -1)
    {
        printf("Ingrese apellido nuevamente: ");
        fflush(stdin);
        gets(myEmployee.lastName);
    }
    printf("Ingrese salario: ");
    scanf("%f",&myEmployee.salary);
    myEmployee.isEmpty = FALSE;
    return myEmployee;

}

int addEmployees(sEmployee* list, int length,int numberId)
{
    int i;
    int retorno = -1;
    i = searchFree(list,length);
    if((length > 0 && length < 1001) && list != NULL)
    {
        if(i != -1)
        {
            list[i] = addEmployee();
            list[i].id = numberId;
            list[i].isEmpty = TRUE;
            retorno = 1;
        }
    }
    return retorno;
}

int printEmployees(sEmployee* list, int length)
{
    int i;
    int retorno = -1;
    if((length > 0 && length < 1001) || list != NULL)
    {
        printf("ID\tSECTOR\t               NOMBRE\t             APELLIDO\t    SALARIO\n");
        for(i = 0; i < length; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                printEmployee(list[i]);
                retorno = 1;
            }

        }
    }
    return retorno;
}

int findEmployeeById(sEmployee* list, int length,int id)
{
    int i;
    int retorno = -1;
    if(list != NULL && length > 0)
    {
        for(i = 0; i < length; i++)
        {
            if(list[i].id == id)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}
int removeEmployee(sEmployee* list, int length)
{
    int id;
    int index;
    int remove;
    int retorno = -1;
    if(list != NULL && length > 0)
    {
        printEmployees(list,length);
        printf("\nIngrese numero ID: ");
        scanf("%d",&id);
        index = findEmployeeById(list,length,id);
        if(index != -1)
        {
            printf("\nEsta seguro que desea eliminar los siguientes datos?: ");
            printEmployee(list[index]);
            printf("\n1.Si\n2.No\n");
            scanf("%d",&remove);
            if(remove == 1)
            {
                list[index].isEmpty = FALSE;
                retorno = 0;
            }
            else if(remove == 2)
            {
                retorno = 1;
            }
            else
            {
                printf("Opcion no valida,Ingrese nuevamente");
                scanf("%d",&remove);
            }
        }
    }
    return retorno;
}


int modEmployee(sEmployee* list,int length)
{
    int id;
    int index;
    int mod;
    int retorno = -1;
    if((length > 0 && length < 1001) || list != NULL)
    {
        printEmployees(list,length);
        printf("\nIngrese numero ID: ");
        scanf("%d",&id);
        index = findEmployeeById(list,length,id);
        if(index != -1)
        {
            while(mod !=5)
            {
                printf("ID\tSECTOR\t               NOMBRE\t             APELLIDO\t    SALARIO\n");
                printEmployee(list[index]);
                printf("\nQue desea modificar?\n1.Nombre\n2.Apellido\n3.Sector\n4.Salario\n5.Terminar ");
                scanf("%d",&mod);
                switch(mod)
                {
                case 1:
                    printf("\nIngrese nuevo nombre: ");
                    fflush(stdin);
                    gets(list[index].name);
                    toLowerCase(list[index].name);
                    firstLetterToUpperCase(list[index].name);
                    retorno = 0;
                    break;

                case 2:
                    printf("\nIngrese nuevo apellido: ");
                    fflush(stdin);
                    gets(list[index].lastName);
                    toLowerCase(list[index].lastName);
                    firstLetterToUpperCase(list[index].lastName);
                    retorno = 0;
                    break;

                case 3:
                    printf("\nIngrese nuevo sector: ");
                    scanf("%d",&list[index].sector);
                    retorno = 0;
                    break;

                case 4:
                    printf("\nIngrese nuevo salario: ");
                    scanf("%f",&list[index].salary);
                    retorno = 0;
                    break;

                case 5:
                    retorno = 1;
                    break;
                default:
                    printf("Opcion no valida\n");
                    break;
                }
            }
        }
    }
    return retorno;
}
int sortEmployees(sEmployee* list,int length,int order)
{
    int i;
    int j;
    sEmployee aux;
    int retorno = -1;
    if((length > 0 && length < 1001) || list != NULL)
    {

        if(valid(list,length) == 1)
        {
            printf("\nDesea ordenar de manera ascendente o descendente?\n1.Ascendente\n2.Descendente\n3.Cancelar\n");
            scanf("%d",&order);
            if(order == 1)
            {
                for(i = 0; i < length-1; i++)
                {
                    for(j = i+1; j < length; j++)
                    {
                        if(list[i].sector > list[j].sector && list[i].isEmpty == TRUE )
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
                for(i = 0; i < length-1; i++)
                {
                    for(j = i+1; j < length; j++)
                    {
                        if(list[i].sector == list[j].sector && list[i].isEmpty == TRUE)
                        {
                            if(strcmp(list[i].lastName,list[j].lastName) > 0)
                            {
                                aux = list[i];
                                list[i] = list[j];
                                list[j] = aux;
                            }
                        }
                    }
                }
                retorno = 0;
            }
            else if(order == 2)
            {
                for(i = 0; i < length-1; i++)
                {
                    for(j = i+1; j < length; j++)
                    {
                        if(list[i].sector < list[j].sector && list[i].isEmpty == TRUE )
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
                for(i = 0; i < length-1; i++)
                {
                    for(j = i+1; j < length; j++)
                    {
                        if(list[i].sector == list[j].sector &&list[i].isEmpty == TRUE)
                        {
                            if(strcmp(list[i].lastName,list[j].lastName) < 0)
                            {
                                aux = list[i];
                                list[i] = list[j];
                                list[j] = aux;
                            }
                        }
                    }
                }
                retorno = 0;
            }
            else if(order == 3)
            {
                retorno = 1;
            }
            else
            {
                printf("\nOpcion no valida,Ingrese nuevamente\n");
                scanf("%d",&order);
            }
        }
    }
    return retorno;
}

int hardcode(sEmployee* list,int length)
{
    int sector[] = {1,1,1};
    char name[][51] = {"Franco","Leo","Lautaro"};
    char lastName[][51] = {"Oliveri","Martinez","Lezama"};
    float salary[] = {30000,30000,30000};
    int numberId[] = {1,2,3};
    int i;
    int retorno = 0;
    for(i = 0; i < length; i++)
    {
        list[i].sector = sector[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].salary = salary[i];
        list[i].id = numberId[i];
        list[i].isEmpty = TRUE;
        retorno = 1;
    }
    return retorno;
}

int valid(sEmployee* list,int length)
{
    int retorno = -1;
    int i = 0;
    if(list[i].isEmpty == TRUE)
    {
        retorno = 1;
    }
    return retorno;
}

void toLowerCase(char string[])
{
    int length;
    int i;
    length = strlen(string);
    for(i = 1; i < length; i++)
    {
        if(string[i] > 64 && string[i] < 91)
        {
            string[i] = string[i] + 32;
        }
    }
}

void firstLetterToUpperCase(char letter[])
{
    if(letter[0] > 96 && letter[0] < 123)
    {
        letter[0] = letter[0] -32;
    }
}
int onlyLetters(char string[])
{
    int length;
    int i;
    int retorno = 1;
    length = strlen(string);
    for(i = 0; i < length; i++)
    {
        if((string[i] > 90 && string[i] < 97) || string[i] < 65 || string[i] > 123)
        {
            retorno = -1;
        }
    }
    return retorno;
}

float average(sEmployee* list,int length)
{
    int i;
    float acumulador = 0;
    int contador = 0;
    float retorno;
    for(i = 0; i < length; i++)
    {
        if(valid(list,length) == 1)
        {
            acumulador = acumulador + list[i].salary;
            contador++;
        }
    }
    retorno = acumulador / contador;
    return retorno;
}

int overAverage(sEmployee* list,int length)
{
    float promedio = average(list,length);
    int i;
    int contador = 0;
    for(i = 0; i < length; i++)
    {
        if(valid(list,length) == 1)
        {
            if(list[i].salary > promedio)
            {
                contador++;
            }
        }
    }
    return contador;
}

