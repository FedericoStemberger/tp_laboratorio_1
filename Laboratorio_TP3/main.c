#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/




int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option = menuPrincipal();
        switch(option)
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("El archivo ha sido cargado correctamente.\n");
            }
            else
            {
                printf("El archivo no se ha cargado correctamente.\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.csv",listaEmpleados))
            {
                printf("El archivo ha sido cargado correctamente.\n");
            }
            else
            {
                printf("El archivo no se ha cargado correctamente.\n");
            }
            break;
        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                printf("El empleado ha sido agregado exitosamente.\n");
            }
            else
            {
                printf("No se ha podido agregar el empleado.\n");
            }
            break;
        case 4:
            if(controller_editEmployee(listaEmpleados))
            {
                printf("El empleado se ha modificado exitosamente.\n");
            }
            else
            {
                printf("Ha habido un problema en la modificación del empleado.\n");
            }
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados) == 0)
            {
                printf("El empleado ha sido removido con exito!\n");
            }
            else
            {
                printf("Hubo un problema al remover el empleado\n");
            }
            break;
        case 6:
            if(!controller_ListEmployee(listaEmpleados))
            {
                printf("Hubo un error al mostrar la lista\n");
            }
            break;
        case 7:
            if(!controller_sortEmployee(listaEmpleados))
            {
                printf("Hubo un problema en el ordenamiento.\n");
            }
            break;
        case 8:
            if(controller_saveAsText("data.csv", listaEmpleados))
            {
                printf("Guardado exitoso.\n");
            }
            else
            {
                printf("No se ha guardado correctamente.\n");
            }
            break;
        case 9:
            if(controller_saveAsBinary("data.bin", listaEmpleados))
            {
                printf("Guardado exitoso.\n");
            }
            else
            {
                printf("No se ha guardado correctamente.\n");
            }
            break;
        }
        system("pause");
    }
    while(option != 10);
    return 0;
}

