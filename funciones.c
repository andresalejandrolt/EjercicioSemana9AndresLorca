//
// Created by Andrés on 21/5/2026.
//

#include "funciones.h"

void limpiarBuffer() {

    while (getchar() != '\n') {
    }
}

void imprimirDatosLibro(Libro *libro) {

    printf("%-100s, %-50s, %-4d, %-10s\n", libro -> titulo,
        libro -> autor, libro -> fechaPublicacion, libro -> estado);


}

void eliminarSaltoLinea(char *titulo) {

    *(titulo + strcspn(titulo, "\n")) = '\0';
}

void presioneContinuar() {

    printf("\nPresion ENTER para continuar\n");
    getchar(); //No iria limpiarBuffer()?
}

float validarIngreso(int validarPositivos) {

    float valor;
    int esValido;

    do {

        esValido = scanf("%f", &valor);

        if (esValido != 1) {

            printf("Error de ingreso, intente de nuevo: ");
            limpiarBuffer();
        }

        if (esValido && validarPositivos) {

            if (valor <= 0) {
                printf("Error, ingrese un numero mayor a 0!: ");
                esValido = 0;
                limpiarBuffer();
            }
        }

    }while (esValido != 1);
    return valor;

}

void nombreAMayusculas(char *nombre) {

    while (*nombre != '0') {
        *nombre = toupper(*nombre);
        nombre++;
    }
}

void actualizarEstadoLibro(Libro *libro) {

    if (libro -> disponible == 0)
        strcpy(libro -> estado, "Prestado");
    else
        strcpy(libro -> estado, "Disponible");

}

int buscarLibro(char *nombreTemp, Libro *libros, int numeroLibros) {

    for (int i = 0; i < numeroLibros; i++) {
        if (strcmp(nombreTemp, (libros + i) -> titulo) == 0) {
            return i;
        }
    }
    return -1;
}


void registrarLibro(int *sigID, Libro *libros, int *numeroLibros) {

    if (*numeroLibros >= MAX_LIBROS) {
        printf("\nError, limite de productos alcanzados!\n");
        return;
    }

    char tituloAux [MAX_CARACTERES_TITULO];

    printf("\n========== REGISTRO DE LIBRO ==========\n");
    printf("Registando libro con ID[%d]\n", *sigID);
    printf("Ingrese el titulo del libro: ");
    fgets(tituloAux, MAX_CARACTERES_TITULO, stdin);
    eliminarSaltoLinea(tituloAux);

    if (strlen(tituloAux) == 0) {
        printf("Nombre invalido\n");
        return;
    }
    nombreAMayusculas(tituloAux);


    int indexRepetido = buscarLibro(tituloAux, libros, *numeroLibros);

    if (indexRepetido != -1) {
        printf("Error, libro ya registrado!\n");
        return;
    }

    strcpy((libros + *numeroLibros)->titulo, tituloAux);
    printf("Ingrese el autor del Libro");




}