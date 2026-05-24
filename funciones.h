//
// Created by Andrés on 21/5/2026.
//

#ifndef EJERCICIOSEMANA9ANDRESLORCA_FUNCIONES_H
#define EJERCICIOSEMANA9ANDRESLORCA_FUNCIONES_H

#define MAX_CARACTERES_TITULO 100
#define MAX_CARACTERES_AUTOR 50
#define MAX_CARACTERES 20
#define MAX_LIBROS 10
#define ANIO_ACTUAL 2026
#define ID_INICIAL 1000

typedef struct {

  int ID;
  char titulo[MAX_CARACTERES_TITULO];
  char autor[MAX_CARACTERES_AUTOR];
  char estado[MAX_CARACTERES];
  int fechaPublicacion;
  int disponible;

}Libro;

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void presioneContinuar();
void limpiarBuffer();
void imprimirDatosLibro(Libro *libro);
void eliminarSaltoLinea(char *titulo);
float validarIngreso(int validarPositivos);
void nombreAMayusculas(char *nombre);
void actualizarEstadoLibro(Libro *libro);
int buscarLibro(char *nombreTemp, Libro *libros, int numeroLibros);
void registrarLibro(int *sigID, Libro *libros, int *numeroLibros);
void ejecutarPrograma();



#endif //EJERCICIOSEMANA9ANDRESLORCA_FUNCIONES_H