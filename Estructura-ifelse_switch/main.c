/*
 * Author:    Juan Alberto Cuevas Juarez
 * Time:      17 Julio 2023
 * Program3:  Funcionamiento de la estructura if-else
*/

#include <stdio.h>                      //directiva de preprocesador

int main(int argc, char **argv){
    //presentation----------------------------------------------------------
    printf(" Author: Juan Alberto Cuevas Juarez \n");
    printf(" Program: imprime mes con estructura if-else \n");
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
  
    
    //estructura if - else
    
        if (mes == 1)
            printf(" Mes de Enero \n");
           else if (mes == 2)
                 printf(" Mes de Febrero \n");
                else if(mes == 3)
                       printf(" Mes de Marzo \n");
                     else if (mes == 4)
                             printf(" Mes de Abril \n");
                             else if(mes == 5)
                                     printf(" Mes de Mayo \n");
                                     else if(mes == 6)
                                             printf(" Mes de Junio \n");
                                             else if(mes == 7)
                                                     printf(" Mes de Julio \n");
                                                     else if(mes == 8)
                                                             printf(" Mes de Agosto \n");
                                                             else if(mes == 9)
                                                                     printf(" Mes de Septiembre \n");
                                                                     else if(mes == 10)
                                                                             printf(" Mes de Octubre \n");
                                                                             else if(mes == 11)
                                                                                     printf(" Mes de Noviembre \n");
                                                                                     else if(mes == 12)
                                                                                             printf(" Mes de Diciembre \n");
                                                                                             else
                                                                                                 printf(" Fuera de rango \n");
                                                                                                 
                                                            
        
        return 0;
  
   }