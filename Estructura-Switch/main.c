/*
 * Author:    Juan Alberto Cuevas Juarez
 * Time:      16 Julio 2023
 * Program2:  Funcionamiento de la estructura switch
*/

#include <stdio.h>                      //directiva de preprocesador

int main(int argc, char **argv){
    //presentation----------------------------------------------------------
    printf(" Author: Juan Alberto Cuevas Juarez \n");
    printf(" Program: imprime mes con estructura switch \n");
    printf(" ------------------------------------------ \n");
    printf("\a");
    printf("\x3C\t  \x7E\t  \x3E\t \n");
    //----------------------------------------------------------------------
    
    
    //declarar variables locales con su tipo de dato y asignacion
    int mes = 0;
    
    //input  and read
    printf(" Ingrese numero de un mes del anio  \n");
    scanf("%d", &mes);
    printf(" Numero ingresado es: %d \n", mes);
    
    //Restriction
    if (mes < 1 || mes > 12){
            printf (" ERROR mes incorrecto \n");
            
            printf(" Ingrese numero de un mes del anio  \n");
            scanf("%d", &mes);
            printf(" Numero ingresado es: %d \n", mes);
        }
    else 
        printf (" datos correctos \n");
        
        
    // estructura switch
    switch (mes) {
        case 1:
           printf(" Mes de Enero \n");
           break;
        case 2:
           printf(" Mes de Febrero \n");
           break;
        case 3:
           printf(" Mes de Marzo \n");
           break;
        case 4:
           printf(" Mes de Abril \n");
           break;
        case 5:
           printf(" Mes de Mayo \n");
           break;
        case 6:
           printf(" Mes de Junio \n");
           break;
        case 7:
           printf(" Mes de Julio \n");
           break;
        case 8:
           printf(" Mes de Agosto \n");
           break;
        case 9:
           printf(" Mes de Septiembre \n");
           break;
        case 10:
           printf(" Mes de Octubre \n");
           break;
        case 11:
           printf(" Mes de Noviembre \n");
           break;
        case 12:
           printf(" Mes de Diciembre \n");
           break;
        default:
        printf(" Fuera de rango \n");
        
        }
    
     return 0;
    }