/*
 * Author:    Juan Alberto Cuevas Juarez
 * Time:      15 Julio 2023
 * Program1:   Volumen de un cilindro
*/

#include <stdio.h>                      //directiva de preprocesador

#define PI 3.141593                 //variable global

int main(int argc, char **argv){
    //presentation----------------------------------------------------------
    printf(" Author: Juan Alberto Cuevas Juarez \n");
    printf(" Program: Volumen de un cilindro \n");
    printf(" ------------------------------------------ \n");
    printf("\a");
    printf("\x3C\t  \x7E\t  \x3E\t \n");
    //----------------------------------------------------------------------
    
    
    //declarar variables locales con su tipo de dato y asignacion
    float d = 0;                              //diametro
                                   
    float h = 0;                              //altura
    
    float r = 0;                              //radio
    
    float v = 0;                             //volumen
    
    printf(" Ingrese diametro: \n");     //ingreso de valor por teclado del usuario.
    scanf(" %f", &d);                   //leer valor, a un espacio reservado de memoria.
    printf(" diametro =  %.2f metros \n \n", d);
    
    printf(" Ingrese altura: \n");
    scanf(" %f", &h);
    printf(" altura =  %.2f metros \n \n", h);
    
    
    //Calculos
             //Calculo de radio
             r = d / 2;
             printf(" El radio es: %.2f metros \n \n", r);
             
             //Recordar a PI como macro global
             printf(" El macro definido es pi: %.6f \n \n", PI);
             
             //Calculo de Volumen
             //v = v + r;
             //v += r;
               v = PI* (r*r) * h;
               
             printf(" El volumen es: %.3f metros cubicos \n \n", v);
             

         return 0;
    }