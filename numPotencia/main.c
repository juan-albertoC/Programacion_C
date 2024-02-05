/**
 * Juan Alberto Cuevas Juarez
 * 07-08-2023
 * Programa: Eleva un numero base a la x potencia
 **/ 

#include <stdio.h>

int potencia(int a, int b);   //Prototipo de la funcion
  
int main(int argc, char **argv) 
{
  /**  
    //programa local trivial test que calcula una potencia de x numero a la n potencia,
	int x=8, n=3, val=1;     //declarar e inicializar variables, x(base), n(exponente)
    
    for(int i=0; i<n; i++){  // loop: i aumenta hasta encontrar al exponente
        val=val*x;              //acumular base la multiplicacion tras aumentar i
                                //asignar operacion en variable val          
        }
    printf("La potencia con base %d de exponente %d es:  %d \n",x,n,val);
    return 0;
     **/
     
    
    //programa funcional que calcula una potencia de x numero a la n potencia,
       int x, n;
       printf("Introduzca la base: ");
       scanf("%d", &x);
       
       printf("Introduzca el exponente: ");
       scanf("%d", &n);
       
       printf("%d elevado a %d vale %d \n", x, n, potencia(x,n)); //llamada de funcion potencia
	
}

//Implementacion de la funcion potencia
int potencia(int a, int b){
       int val=1;
       for(int i=0; i<b; i++){  // loop: i aumenta hasta encontrar al exponente
        val=val*a;              //acumular base la multiplicacion tras aumentar i
                                //asignar operacion en variable val          
        }
      return val;
    }
    
    