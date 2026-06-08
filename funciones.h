#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIBROS 10
#define MAX_CARACTERES_TITULO 100
#define MAX_CARACTERES_AUTOR 50
#define ANIO_ACTUAL 2026
#define ID_INICIAL 1

typedef struct {
    int ID;
    char titulo[MAX_CARACTERES_TITULO];
    char autor[MAX_CARACTERES_AUTOR];
    int fechaPublicacion;
    int disponible;
    char estado[12];
} Libro;

void limpiarBuffer();
void imprimirDatosLibros(Libro *libros, int numeroLibros);
void imprimirUnLibro(Libro *libro);
void eliminarSaltoLinea(char *titulo);
void presioneContinuar();
float validarIngreso(int validarPositivos);
void nombreAMayusculas(char *nombre);
void actualizarEstadoLibro(Libro *libro);
int buscarLibro(char *nombreTemp, Libro *libros, int numeroLibros);
int buscarLibroPorID(int id, Libro *libros, int numeroLibros);
void buscarYMostrarLibro(Libro *libros, int *numeroLibros);
void cambiarEstadoLibro(Libro *libros, int *numeroLibros);
void eliminarLibro(Libro *libros, int *numeroLibros);
void registrarLibro(int *sigID, Libro *libros, int *numeroLibros);
void ejecutarPrograma();

#endif