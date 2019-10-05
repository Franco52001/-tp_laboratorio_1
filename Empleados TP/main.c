#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#define A 3



int main()
{
    sEmployee listEmployees[A];
    int option;
    int retorno;
    int numeroId = 1;
    int baja;
    int mod;
    int orden;
    float promedio;
    int employeeOverAverage;
    int submenu;
    if(initEmployees(listEmployees,A) == 0)
    {
        do
        {
            printf("\nElija una opcion\n");
            printf("1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                retorno = addEmployees(listEmployees,A,numeroId);
                //retorno = hardcode(listEmployees,A);
                if(retorno == 1)
                {
                    numeroId++;
                    printf("Cargado con exito\n");
                }
                else
                {
                    printf("No hay espacio disponible\n");
                }
                break;
            case 2:
                mod  = modEmployee(listEmployees,A);
                switch(mod)
                {
                case 0:
                    printf("\nDatos modificados\n");
                    printEmployees(listEmployees,A);
                    break;
                case 1:
                    printf("\nAccion terminada\n");
                    printEmployees(listEmployees,A);
                    break;
                case -1:
                    printf("\nDatos no encontardos\n");
                    break;
                }
                break;
            case 3:
                baja = removeEmployee(listEmployees,A);
                switch(baja)
                {
                case 0:
                    printf("\nDatos eliminados\n");
                    printEmployees(listEmployees,A);
                    break;
                case 1:
                    printf("\nAccion cancelada\n");
                    printEmployees(listEmployees,A);
                    break;
                case -1:
                    printf("\nDatos no encontardos\n");
                    break;
                }
                break;
            case 4:
                printf("\nElija una opcion\n");
                printf("1.Listado de los empleados\n2.Promedio de salarios\n");
                scanf("%d",&submenu);
                switch(submenu)
                {
                case 1:
                    orden = sortEmployees(listEmployees,A,orden);
                    switch(orden)
                    {
                    case 0:
                        printf("\nDatos ordenados\n");

                        printEmployees(listEmployees,A);
                        break;
                    case 1:
                        printf("\nAccion cancelada\n");
                        printEmployees(listEmployees,A);
                        break;
                    case -1:
                        printf("\nDatos no encontardos\n");
                        break;

                    }
                    break;
                case 2:
                    if(valid(listEmployees,A) == 1)
                    {
                        promedio = average(listEmployees,A);
                        printf("%f",promedio);
                        employeeOverAverage = overAverage(listEmployees,A);
                        printf("\nEl numero de empleados que tiene un salario superior al promedio es: %d",employeeOverAverage);
                    }
                    else if(valid(listEmployees,A) == -1)
                    {
                        printf("\nNo se han ingresado datos\n");
                    }
                    break;
                }
            }
        }
        while(option != 5);
    }
    else
    {
        printf("ERROR");
    }

}
