/**
 * Juan Alberto Cuevas Juarez
 * 07-08-2023
 * Programa: Suma los elementos de un vector, crear funciones para visualizar vector y otra funcion para sumar los elementos
 **/ 


//directivas del preprocesador
#include <stdio.h>
#define N 30                 //define un tamanio maximo de elementos en el vector

//Prototipos
void viewVector(int vector[N],int n);     //visualizar vector
void sumaVector(int vector[N],int n);     //sumar vector

int main(int argc, char **argv)
{
	 int vector[N];                       //crear el vector
     int n;                               //variable para un tamanio especifico del vector

     
     //Input
     printf("\nIngresa dimension del vector\n");  // n tamanio especifico
     scanf("%d", &n);                             //guardar referencia en n
     //input
     printf("\nIngresa elementos del vector \n");
     for(int i=0; i<n; i++)
      {
          printf("Elemento: [%d] : ", i);         
                 scanf("%d", &vector[i]);         //guardar los elementos en el vector  desde 0 hasta n, va ir aumentando la varible i y guardar los datos
      }
      
      viewVector(vector,n);   //llamada de la funcion
      sumaVector(vector,n);   //llamada de la funcion
     
	return 0;
}


//Implementaciones

void viewVector(int vector[N],int n)             //recibe dos parametros
{
    printf("\nVisualizacion del vector: \n");
      for(int i=0; i<n; i++)                    
       {
          printf("%d\t ",vector[i]);            //muestra el vector de forma tabular
       }
            printf("\n\n");                     //saltos de linea

}

void sumaVector(int vector[N],int n)           //recibe dos parametros
{   
    
   int suma = 0;                               //declara e iniciliza suma en 0
   //for(int j=0; j<=n; j++)
    //{     
      //  suma += vector[j];
       
    //}
    int j = 0;                                //variable contadora
    while(j<n)                                 //mientras que la condicion se cumpla
    {
        
        suma += vector[j];                     //hacer la suma del vector
        ++j;                                   //tantas veces sea necesario contador aumenta
    }
    printf("La suma es: %d ",suma);
}
