//
// Created by Andrés on 21/5/2026.
//

#ifndef EJERCICIOSEMANA9ANDRESLORCA_FUNCIONES_H
#define EJERCICIOSEMANA9ANDRESLORCA_FUNCIONES_H

#define MAX_CARACTERES_TITULO 100
#define MAX_CARACTERES_AUTOR 50
#define MAX_CARACTERES 20
#define MAX_LIBROS 10

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
void agregarLibro();



#endif //EJERCICIOSEMANA9ANDRESLORCA_FUNCIONES_H