/**
 * Juan Alberto Cuevas Juarez
 * 17-08-2023
 * Programa: Estructura de una cancion, pasar los parametros por referencia
 **/ 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cancion.h>    //se agrega el archivo cancion.h para ser utilizado

//Estructura en cancion.h
//struct cancion
//{
  //  char titulo[30];      //char de tamanio 30 bytes
  //  char artista[30];
  //  char duracion[20];
 //   char tamanio[20];

//};

//Prototipos
void input(struct cancion* ptro);         //estructura con un puntero
void output(struct cancion ptr);          //estructura sin puntero

void main()                              //main principal de tipo void
{   
    //------------------------------------------------------------//
    printf("\t -------------Problem: Struct de una cancion mp3--------------\n\n");
    
    
        struct cancion song1;    //definir o crear una estructura de tipo cancion
        
	    //sizeof permite saber el tamanio en bytes de la estructura creada
       
       printf("sizeof song1 object = %lu bytes\n",sizeof(song1));
       
       input(&song1);                   //llamada de paso por referencia, es la direccion
       
       output(song1);                  //paso por valor
       
       getchar();                      //detiene programa
       
	 
}

//implemnetacions
void input(struct cancion* ptro)
{
    printf("Enter Titulo: "); 
    gets(ptro->titulo);   //accede puntero hacia el atributo con -> selector
    printf("Enter Artista: "); 
    gets(ptro->artista);
    printf("Enter Duracion: "); 
    gets(ptro->duracion);
    printf("Enter Tamanio: "); 
    gets(ptro->tamanio);
    
}

void output(struct cancion ptr)
{
    printf("Visualizar datos de cancion:  \n\n");
    printf("%s\t",ptr.titulo);      //obtiene el dato almacenado con el operador punto 
    printf("%s\t",ptr.artista);
    printf("%s\t",ptr.duracion);
    printf("%s\t",ptr.tamanio);


}


    