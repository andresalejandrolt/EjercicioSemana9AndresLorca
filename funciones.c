//
// Created by Andrés on 21/5/2026.
//

#include "funciones.h"

void limpiarBuffer() {
    while (getchar() != '\n') {
    }
}

void imprimirDatosLibro(Libro *libro) {

    printf("%8d | %30s | %15s | %16d | %10s\n", libro->ID, libro->titulo,
           libro->autor, libro->fechaPublicacion, libro->estado);
}

void eliminarSaltoLinea(char *titulo) {
    *(titulo + strcspn(titulo, "\n")) = '\0';
}

void presioneContinuar() {
    printf("\nPresione ENTER para continuar\n");
    // limpiarBuffer();
    getchar();
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
    } while (esValido != 1);

    limpiarBuffer();

    return valor;
}

void nombreAMayusculas(char *nombre) {
    while (*nombre != '\0') {
        *nombre = toupper(*nombre);
        nombre++;
    }
}

void actualizarEstadoLibro(Libro *libro) {
    if (libro->disponible == 0)
        strcpy(libro->estado, "Prestado");
    else
        strcpy(libro->estado, "Disponible");
}

int buscarLibro(char *nombreTemp, Libro *libros, int numeroLibros) {
    for (int i = 0; i < numeroLibros; i++) {
        if (strcmp(nombreTemp, (libros + i)->titulo) == 0) {
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

    char tituloAux[MAX_CARACTERES_TITULO];
    char autorAux[MAX_CARACTERES_AUTOR];
    int fechaPublicacionAux;


    printf("\n========== REGISTRO DE LIBRO ==========\n");
    printf("\nRegistando libro con ID[%d]\n", *sigID);
    printf("\nIngrese el titulo del libro: ");
    fgets(tituloAux, MAX_CARACTERES_TITULO, stdin);
    eliminarSaltoLinea(tituloAux);

    if (strlen(tituloAux) == 0) {
        printf("Nombre invalido\n");
        return;
    }
    nombreAMayusculas(tituloAux);

    int indexRepetido = buscarLibro(tituloAux, libros, *numeroLibros);

    if (indexRepetido != -1) {
        printf("\nERROR, libro ya registrado!\n");
        return;
    }

    printf("Ingrese el Autor del libro: ");
    fgets(autorAux, MAX_CARACTERES_AUTOR, stdin);
    eliminarSaltoLinea(autorAux);
    nombreAMayusculas(autorAux);

    printf("Ingrese la fecha de publicacion libro: ");

    fechaPublicacionAux = (int) validarIngreso(0);

    while (fechaPublicacionAux > ANIO_ACTUAL) {
        printf("Error, ingrese un anio menor o igual al actual! : ");
        fechaPublicacionAux = (int) validarIngreso(1);
    }

    Libro libroAux;

    strcpy(libroAux.titulo, tituloAux);
    strcpy(libroAux.autor, autorAux);
    libroAux.fechaPublicacion = fechaPublicacionAux;
    libroAux.disponible = 1;
    actualizarEstadoLibro(&libroAux);
    libroAux.ID = *sigID;

    *(libros + *numeroLibros) = libroAux;

    (*sigID)++;
    (*numeroLibros)++;

    printf("\nLibro Registrado Correctamente!\n");
}



void ejecutarPrograma() {

    Libro libros[MAX_LIBROS];
    int numeroLibros = 0;
    int sigID = ID_INICIAL;
    int flag = 1;

    int opUsuario = 0;

    do {
        printf("\n===== SISTEMA GESTION BIBLIOTECA =====\n");
        printf("1. %35s\n", "Agregar un nuevo libro");
        printf("2. %35s\n", "Mostrar todos los libros");
        printf("3. %35s\n", "Buscar un libro existente");
        printf("4. %35s\n", "Actualizar estado de un libro");
        printf("5. %35s\n", "Eliminar un libro existente");
        printf("0. %35s\n", "Salir del programa");
        printf("Ingrese una opcion: ");

        opUsuario = (int) validarIngreso(0);

        switch (opUsuario) {

            case 0 : {
                flag = 0;
                printf("\nSaliendo del programa...\n");
                presioneContinuar();
                break;
            }

            case 1 : {
                registrarLibro(&sigID, libros, &numeroLibros);
                presioneContinuar();
                break;
            }

            case 2 : {

                printf("\n%-8s | %-30s | %-15s | %-16s | %-10s\n", "ID LIBRO", "TITULO LIBRO",
                "AUTOR LIBRO", "ANIO PUBLICACION", "ESTADO");

                for (int i = 0; i < numeroLibros; i++) {

                    imprimirDatosLibro(&libros[i]);

                }

            }
            case 3 : {

            }
            case 4 : {

            }
            case 5 : {

            }



        }





    }while (flag);

}

