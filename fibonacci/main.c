/**
 * Juan Alberto Cuevas Juarez
 * 20-08-2023
 * Programa: Serie de Fibonacci modo Iterativo y modo Recursivo con funciones
 **/ 

//directivas preprocesador
#include <stdio.h>

//Declarar Prototipos o Algoritmos 
long fibonaccItera(int f);
long fibonacciRecurs(int f);

//funcion principal

int main(int argc, char **argv)
{
    //Input variables
    int n,opcion;
    
    do {
        printf("\t -------------Algoritmo: Serie de numeros de Fibonacci--------------\n\n");
        
        printf("Introduce numero(n) calcular la serie de fibonacci:  \n\n");
          scanf("%d",&n);
        }while (n<=1);
        
        //---------------------------------------------------------------//
        printf("Pulse tecla 1 para modo Iterativo o tecla 2 para modo Recursivo: \n\n");
        scanf("%d",&opcion);
        if(opcion == 1)
        {
            printf("Es el modo Iterativo  \n\n");
            printf("Serie de Fibonacci de numero %d:  \n\n", n);
            for(int x = 2; x <= n; x++)   //visualizar serie
            {
                //llamada de la funcion, se cumple condicion aumentar un espacio en blanco al resultado
              printf("%ld%c", fibonaccItera(x),(x%7==0 ?'\n':' '));  //expresion condicional con el operador ? ternario, sus tres operandos division obtener resto 
            }
        
        } else
              if(opcion == 2)
               {
                    printf("Es el modo Recursivo, Caso Base: 0,1, caso general suma (n-2)+(n-1) los dos ultimos valores\n\n");
                    printf("Serie de Fibonacci de numero %d:  \n\n", n);
                    for(int x = 2; x <= n; x++)
                    {
                      printf("%ld%c", fibonaccItera(x),(x%7==0 ?'\n':' '));
                    //printf("\t%ld",fibonaccItera(x));   //llamada de la funcion         
                    }
                  
               }
               else
                 printf("Opcion incorrecta, intente de nuevo: \n");
        
    
    //------------------------------------------------------------------------------------//
    
    
	return 0;
}

//Implementacion de Algoritmos
long fibonaccItera(int f)            //recibe parametro f por referencia de n
{
    
    int A = 0;       //declarar variable y asignar
    int B = 1;
    int suma;       
    
    if (f == 1) return 0;          //elemento 0 
      else if(f == 2) return 1;    //elemento 1
      
      for(int i = 3; i <= f; i++ )     //ciclo for para sumar los dos ultimos valores y recorrer la posicion A y B
      {
          suma = A + B;   //operacion
          A = B;         //actualizar variable A
          B = suma;      //actualizar variable B
      } 

    return suma;        //retorna un valor long de f   

}

long fibonacciRecurs(int f)
{
    if (f == 0 || f == 1)
        return f;
    else
        return fibonacciRecurs(f - 2) + fibonacciRecurs(f - 1);
    
}