#include <stdio.h>
#include <string.h>
#include "funciones.h"


void registrarLibros(struct Libro libros[], int i)
{
    int len;

    printf("Ingrese el id del libro: ");
    scanf("%d", &libros[i].id);

    getchar();  

    printf("Ingrese el titulo del libro: ");
    fgets(libros[i].titulo, 50, stdin);
    len = strlen(libros[i].titulo) - 1;
    if (libros[i].titulo[len] == '\n') 
        libros[i].titulo[len] = '\0';  

    
    printf("Ingrese el autor del libro: ");
    fgets(libros[i].autor, 50, stdin);
    len = strlen(libros[i].autor) - 1;
    if (libros[i].autor[len] == '\n') 
        libros[i].autor[len] = '\0'; 

    printf("Ingrese el año de publicacion del libro: ");
    scanf("%d", &libros[i].anio_publicacion);
}

void mostrarLibros(struct Libro libros[], int n)
{
     printf("%-10s %-20s %-20s %-10s %-10s\n", "ID", "Titulo", "Autor", "Año de publicacion", "Estado");

    for (int i = 0; i < n; i++)
    {
        if (strcmp(libros[i].estado, "Disponible") == 0)
        {
            // Imprimir información del libro
            printf("%-10d %-20s %-20s %-10d %-10s\n",
                   libros[i].id,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio_publicacion,
                   libros[i].estado);
        }
    }
}

void buscarLibroId(struct Libro libros[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("Libro encontrado:\n");
            printf("%-10d %-20s %-20s %-10d %-10s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio_publicacion, libros[i].estado);
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}
