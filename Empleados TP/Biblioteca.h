#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

/** \brief Inicia todas las posiciones del array en cero
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Tipo de dato que retorna para confirmar la inicializacion
 * \return int Confirmacion de la inicializacion
 *
 */
int initEmployees(sEmployee*,int);
/** \brief Pide los datos de un empleado y se los asigna al array
 *
 * \return sEmployee Retorna los datos al array
 *
 */
sEmployee addEmployee();
/** \brief Pide los datos de todos los empleados por medio de un for
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \param numberId int Numero al cual se le asignara el ID
 * \return int Devuelve 1 si se ingresaron los datos -1 si el array ya estaba lleno
 *
 */
int addEmployees(sEmployee*,int len,int numberId);
/** \brief Busca a un empleado en base a su ID
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \param numberId int Numero al cual se le asignara el ID
 * \return int Devolvera -1 si no se encontro al empleado o devolvera la posicion del array que coincida con el id ingresado
 *
 */
int findEmployeeById(sEmployee*,int len,int numberId);
/** \brief Permitira remover un empleado del array
 *
 * \param sEmployee*  Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \return int Devolvera 0 si se logro eliminar al empleado 1 si se cancelo la operacion o -1 si no lo encontro
 *
 */
int removeEmployee(sEmployee*,int len);
/** \brief Permitira modificar los datos de un empleado
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \return int Devolvera 0 si se logro modificar al empleado 1 si se cancelo la operacion o -1 si no lo encontro
 *
 */
int modEmployee(sEmployee*,int len);
/** \brief Ordenara los empleados por sector y a los empleados del mismo sector los ordenara por apellido
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \param order int
 * \return int
 *
 */
int sortEmployees(sEmployee*,int len,int order);
/** \brief Muestra un empleado y sera la estructura que se usara para mostrar a todos
 *
 * \param oneEmployee sEmployee Puntero del array de empleados
 * \return void
 *
 */
void printEmployee(sEmployee);
/** \brief Muestra a todos los empleados
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \return int Devolvera 1 si se encontraron datos dentro del limite y -1 si no se encontraron datos dentro del limite
 *
 */
int printEmployees(sEmployee*,int len);
/** \brief  Se asegura de que haya espacio disponible en el array
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \return int
 *
 */
int searchFree(sEmployee*,int len);
/** \brief Funcion que agiliza el testeo mediante el ingreso automatico de datos predefinidos
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitidos
 * \return int Devuelve 1 si se ingresaron los datos -1 si el array ya estaba lleno
 *
 */
int hardcode(sEmployee*,int len);
/** \brief Funcion que se encarga de validar espacios en el array
 *
 * \param sEmployee* Puntero del array de empleados
 * \param len int Limite de empleados ingresados permitido
 * \return int Devuelve 1 si hay espacio y 0 si no hay
 *
 */
int valid(sEmployee*,int len);
/** \brief Funcion que vuelve mayusculas en minusculas, usada para nombres y apellidos
 *
 * \param char[] Cadena de caracteres que va a revisar
 * \return void
 *
 */
void toLowerCase(char[]);
/** \brief Funcion utilizada para volver la primera letra de un nombre o apellido en mayuscula
 *
 * \param char[] Cadena de caracteres que va a revisar
 * \return void
 *
 */
void firstLetterToUpperCase(char[]);
/** \brief Funcion utilizada para validar que en un nombre o apellido no se usen numeros
 *
 * \param char Cadena de caracteres que va a revisar
 * \return int Devuelve -1 si encontro un numero y 1 si no encontro ningun numero
 *
 */
int onlyLetters(char[]);
/** \brief Funcion utilizada para sacar promedio
 *
 * \param sEmployee* Puntero del array de empleados
 * \param int Limite de empleados ingresados permitido
 * \return float Devuelve el promedio final
 *
 */
float average(sEmployee*,int);
/** \brief Funcion utilizada para encontrar empleados que ganen mas que el promedio
 *
 * \param sEmployee* Puntero del array de empleados
 * \param int Limite de empleados ingresados permitido
 * \return int Devuelve la cantidad de empleados que estan por encima del promedio
 *
 */
int overAverage(sEmployee*,int);
