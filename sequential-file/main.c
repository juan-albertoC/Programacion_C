/**
 * Juan Alberto Cuevas Juarez
 * 21-08-2023
 * Programa: Archivo secuencial con menu
 * from by https://github.com/kgisl/cs8251/blob/master/notes/unit5.md
 * 
 * Archivo de texto: Es un flujo de caracteres que se puede procesar deforma secuencial y logica en direccion hacia adelante.El numero maximo de caracteres en cada linea esta limitado a 255 cacratres
 * 
 * Archivo binario: Es una coleccion de bytes o un flujo e carcteres. Los datosque se escriben y se leeen en un archivo binario permnecen sin cambios, sin separacion entre lineas ni uso de caracteres de finl de linea y lainterprestacion delarchvo quedaen manos del programaor
 * 
 * Sequential file access: In case of sequential file access, data is read from or written to a file in a sequential manner while the position indicator automatically gets adjusted by the stream I/O functions.
 * 
 * A file represents a sequence of bytes on the disk where a group of related data is stored. File is created for permanent storage of data. It is a readymade structure.
 * 
 * structure pointer of file type to declare a file.
 * 
 * --------------------------------------------------------------------
 * fopen() 	create a new file or open a existing file 	FILE *fp =fopen (“filename”, ”‘mode”);
fclose() 	closes a file 	int fclose(FILE *fp);
 * fgets() 	get a string from file 	char *fgets( char *str, int count, FILE *stream );
 * getc() 	reads a character from a file 	int getc( FILE *stream );
putc() 	writes a character to a file 	int putc( int ch, FILE *stream );
fscanf() 	reads a set of data from a file 	int fscanf( FILE *stream, const char *format, ... );
fprintf() 	writes a set of data to a file 	int fprintf(FILE *fp, const char *format, …)
getw() 	reads a integer from a file 	int getw(FILE *fp);
putw() 	writes a integer to a file 	int putw(int w, FILE *stream); (deprecated, legacy)
fseek() 	set the position to desire point 	int fseek( FILE *stream, long offset, int origin );
ftell() 	gives current position in the file 	long ftell( FILE *stream );
rewind() 	set the position to the beginning point 	void rewind( FILE *stream );
fread() 	reads specific number of bytes from binary file 	size_t fread( void *buffer, size_t size, size_t count, FILE *stream);
fwrite() 	writes specific number of bytes to binary files 	size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream);
 * 
 * int fclose ( FILE *fp ); Here fclose() function closes the file and returns zero on success, or EOF if there is an error in closing the file. This EOF is a constant defined in the header file stdio.h.
 * 
 * Types of file processing

    There are two types of files - text and binary files
    There are two techniques for processing files - sequential and random

Every open file has an associated file position indicator, which describes where read and write operations take place in the file. The position is always specified in bytes from the beginning of the file. When a new file is opened, the position indicator is always at the beginning of the file, i.e., at position 0.

    Writing and reading operations occur at the location of the position indicator and update the position indicator as well. Thus, if one wishes to read all the data in a file sequentially or write data to a file sequentially, it is not necessary to be concerned about the position indicator because the stream I/O functions take care of it automatically.

    When more control is required, the C library functions that help determine and change the value of the file position indicator, have to be used. By controlling the position indicator, random access of a file can be made possible. Here, random means that data can be read from, or written to, any position in a file without reading or writing all the preceding data.
     * 
     * Buffer is a temporary storage area that holds data while they are being transferred to and from memory. Buffering is a scheme that prevents excessive access to a physical I/O device like a disk or a terminal. Its purpose is to synchronize the physical devices that the program needs. The buffer collects output data until there are enough to write efficiently. The buffering activities are taken care of by software called device drivers or access methods provided by the operating system.

 * 
 **/ 

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>     

//Estructura  Libro
struct libro {
    unsigned int id;
    char titulo[60];
    char autor[60];
    char editorial[60];
    int agedition;
    int isbn;
    int paginas;
    double precio;
};

//declaracion de Prototipos
void agregarLibro(FILE *archivo);
void mostrarLibro(struct libro *libro);
void listarLibros(FILE *archivo);
void buscarYModificarLibro(FILE *archivo);
void eliminarLibro(FILE *archivo);



//function main
int main(int argc, char **argv) {
    FILE *archivo;                              //puntero archivo
    int opcion;                                 //opcion para menu

    archivo = fopen("libros.dat", "ab+");       //ab+ opens a binary file in append mode

    if (archivo == NULL) {                      //si no existe manda error
        perror("Error al abrir el archivo");
        return 1;
    }

    do {                                       //do-while
        printf("Menú:\n");
        printf("1. Agregar libro\n");
        printf("2. Listar libros\n");
        printf("3. Modificar libro\n");
        printf("4. Eliminar libro\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);                  //input guarda en variable opcion

        switch (opcion) {
            case 1:
                agregarLibro(archivo);          //llamada de la funcion parametro el archivo
                break;                         //pasa al siguiente caso
            case 2:
                listarLibros(archivo);
                break;
            case 3:
                buscarYModificarLibro(archivo);
                break;
            case 4:
                eliminarLibro(archivo);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);                              //condicion while

    fclose(archivo);                                   //cierra el archivo

    return 0;
}


//Implementaciones de funciones o algoritmos

void agregarLibro(FILE *archivo) {                  //funcion que crea un nuevo libro
                                                    //parametro crea un puntero archivo de File
    struct libro nuevoLibro;                        //variable nuevoLibro de structura libro

    printf("Ingrese los datos del libro:\n");
    printf("ID: ");
    scanf("%u", &nuevoLibro.id);
    fflush(stdin);             //stdin es flujo  standard
    printf("Título: ");
    fgets(nuevoLibro.titulo, sizeof(nuevoLibro.titulo), stdin);  //obtiene una cadena del archivo lo guarda en la estructura nuevoLibro con el operador punto haciala variable titulo como un flujo de entrada y tamanio
    printf("Autor: ");
    fgets(nuevoLibro.autor, sizeof(nuevoLibro.autor), stdin); //flujo de entrada esrandar permite que un programa lea  datos desde el teclado, este se manipula mediante un puntero de archivos stdin, stderr,stdout en caso de flujo de salida estandar. permiten una comunicacion entre archivo y programas
    printf("Editorial: ");
    fgets(nuevoLibro.editorial, sizeof(nuevoLibro.editorial), stdin);
    printf("Año de edición: ");
    scanf("%d", &nuevoLibro.agedition);
    printf("ISBN: ");
    scanf("%d", &nuevoLibro.isbn);
    printf("Páginas: ");
    scanf("%d", &nuevoLibro.paginas);
    printf("Precio: ");
    scanf("%lf", &nuevoLibro.precio);

    // Escribir el libro en el archivo mientras que este abierto 1
    fwrite(&nuevoLibro, sizeof(struct libro), 1, archivo); 
}

void mostrarLibro(struct libro *libro) { //crea struct libro dentro de parametros ademas apunta a libro     
    printf("ID: %u\n", libro->id);                        //formato a visualizar libro
    printf("Título: %s", libro->titulo);
    printf("Autor: %s", libro->autor);                    //libro es puntero
    printf("Editorial: %s", libro->editorial);
    printf("Año de edición: %d\n", libro->agedition); 
    printf("ISBN: %d\n", libro->isbn);     //ocupa operador -> para acceder al dato
    printf("Páginas: %d\n", libro->paginas);
    printf("Precio: %.2lf\n", libro->precio);
}

void listarLibros(FILE *archivo) {   //parametro similar File *archivo  en  int main
    struct libro libroActual;

    rewind(archivo); //establece la posicion en punto inicial, es decir mueve el control al inicio del archivo
    while (fread(&libroActual, sizeof(struct libro), 1, archivo) == 1) {
        mostrarLibro(&libroActual); //llamada de la funcion mostrar, es decir del formato a mostrar, usa ampersam & para referirse o referenciar una funcion creada de tipo void
        printf("------------\n");
    }
}

void buscarYModificarLibro(FILE *archivo) {
    unsigned int idBuscar;          //entero unico para el id
    struct libro libroActual;      //nueva variable donde se guardan los nuevos datos
    int encontrado = 0;           //como un contador o bandera flag, en 0, cambia hasta que se modifique

    printf("Ingrese el ID del libro a modificar: ");
    scanf("%u", &idBuscar);  //el nuevo id se guarda en esta variable

    rewind(archivo);//modificar
    while (fread(&libroActual, sizeof(struct libro), 1, archivo) == 1) {  //
        if (libroActual.id == idBuscar) {    //igualdad de id's
            printf("Datos actuales del libro:\n");
            mostrarLibro(&libroActual); //guarda

            printf("Ingrese los nuevos datos del libro:\n");
            printf("Título: ");
            fflush(stdin);
            fgets(libroActual.titulo, sizeof(libroActual.titulo), stdin);
            printf("Autor: ");
            fgets(libroActual.autor, sizeof(libroActual.autor), stdin);
            printf("Editorial: ");
            fgets(libroActual.editorial, sizeof(libroActual.editorial), stdin);
            printf("Año de edición: ");
            scanf("%d", &libroActual.agedition);
            printf("ISBN: ");
            scanf("%d", &libroActual.isbn);
            printf("Páginas: ");
            scanf("%d", &libroActual.paginas);
            printf("Precio: ");
            scanf("%lf", &libroActual.precio);

            fseek(archivo, -sizeof(struct libro), SEEK_CUR); //fseek busca en desplazamiento el numero e byres a buscar, donde este el archivo apuntado por la secuebcia, ositivo busca hacia adelante, desplazamiento negativo buca hacia atras. seekcur indica ubicacion donde comienzala busqyeda, fseekmueve el  control de lectura a diferentes posiciones en el archivo
            fwrite(&libroActual, sizeof(struct libro), 1, archivo);
            
            printf("Libro modificado correctamente.\n");
            encontrado = 1; //ahora la variable encontrado cambia de 0 a 1 ya se ha modificado
            break;
        }
    }

    if (!encontrado) {     //logica negacion
        printf("Libro con ID %u no encontrado.\n", idBuscar);
    }
}

void eliminarLibro(FILE *archivo) {
    unsigned int idEliminar;
    struct libro libroActual;
    FILE *tempArchivo = fopen("temp.dat", "wb");

    if (tempArchivo == NULL) {
        printf("Error al crear archivo temporal.\n");
        return;
    }

    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%u", &idEliminar);

    rewind(archivo);
    while (fread(&libroActual, sizeof(struct libro), 1, archivo) == 1) {
        if (libroActual.id != idEliminar) {
            fwrite(&libroActual, sizeof(struct libro), 1, tempArchivo); 
        }
    }

    //fwrite transiee un numero especifico de bytes comenxanso en una ubvcacion especifica en  memoria a un file

    fclose(archivo);
    fclose(tempArchivo);

    remove("libros.dat");
    rename("temp.dat", "libros.dat");

    printf("Libro eliminado correctamente.\n");
}


