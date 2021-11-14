#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data2.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data2.dat (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);


    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    printf("\n/****************************************************");
        printf("\nMenu:");
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)..");
        printf("\n9. Guardar los datos de los empleados en el archivo data.dat (modo binario).");
        printf("\n10. Salir");
        printf("\n*****************************************************/\n");
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("data.dat", listaEmpleados);
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("data.dat", listaEmpleados);
            	break;
        }
        utn_getNumero(&option, "Ingrese una opcion", "Error", 0, 10, 2);
    }while(option != 10);


    return 0;
}

