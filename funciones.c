#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarCliente(char clientes[][2][MAX_LONGITUD], int *numClientes) {
    if (*numClientes >= MAX_CLIENTES) {
        printf("No se pueden ingresar más clientes.\n");
        return;
    }
    printf("Ingrese el nombre del cliente: ");
    fgets(clientes[*numClientes][0], MAX_LONGITUD, stdin);
    clientes[*numClientes][0][strcspn(clientes[*numClientes][0], "\n")] = 0;  // Elimina el salto de línea
    printf("Ingrese el ID del cliente: ");
    fgets(clientes[*numClientes][1], MAX_LONGITUD, stdin);
    clientes[*numClientes][1][strcspn(clientes[*numClientes][1], "\n")] = 0;  // Elimina el salto de línea
    (*numClientes)++;
    printf("Cliente ingresado con éxito.\n");
}

void verPeliculas(char peliculas[][4][MAX_LONGITUD], char horarios[][MAX_HORARIOS][MAX_LONGITUD], int numPeliculas) {
    printf("Películas disponibles:\n");
    for (int i = 0; i < numPeliculas; i++) {
        printf("%d. %s\n", i + 1, peliculas[i][0]);
        printf("   Horarios:\n");
        for (int j = 0; j < MAX_HORARIOS; j++) {
            printf("   %d. %s\n", j + 1, horarios[i][j]);
        }
    }
}

void buscarPelicula(char peliculas[][4][MAX_LONGITUD], int numPeliculas) {
    char nombre[MAX_LONGITUD];
    printf("Ingrese el nombre de la película a buscar: ");
    fgets(nombre, MAX_LONGITUD, stdin);
    nombre[strcspn(nombre, "\n")] = 0;  // Elimina el salto de línea

    for (int i = 0; i < numPeliculas; i++) {
        if (strcasecmp(peliculas[i][0], nombre) == 0) {
            printf("Película encontrada:\n");
            printf("Título: %s\n", peliculas[i][0]);
            printf("Director: %s\n", peliculas[i][1]);
            printf("Género: %s\n", peliculas[i][2]);
            printf("Año: %s\n", peliculas[i][3]);
            return;
        }
    }
    printf("Película no encontrada.\n");
}

void comprarTicket(char peliculas[][4][MAX_LONGITUD], char horarios[][MAX_HORARIOS][MAX_LONGITUD], float precios[], char reservas[][3][MAX_LONGITUD], int *numCompras) {
    int peliculaSeleccionada;
    int tipoEntrada;
    int horarioSeleccionado;
    char nombreCliente[MAX_LONGITUD];

    printf("Seleccione la película:\n");
    for (int i = 0; i < MAX_PELICULAS; i++) {
        printf("%d. %s\n", i + 1, peliculas[i][0]);
    }
    scanf("%d", &peliculaSeleccionada);
    getchar();  // Limpia el buffer de entrada
    peliculaSeleccionada--;

    if (peliculaSeleccionada < 0 || peliculaSeleccionada >= MAX_PELICULAS) {
        printf("Selección de película no válida.\n");
        return;
    }

    printf("Seleccione el horario:\n");
    for (int i = 0; i < MAX_HORARIOS; i++) {
        printf("%d. %s\n", i + 1, horarios[peliculaSeleccionada][i]);
    }
    scanf("%d", &horarioSeleccionado);
    getchar();  // Limpia el buffer de entrada
    horarioSeleccionado--;

    if (horarioSeleccionado < 0 || horarioSeleccionado >= MAX_HORARIOS) {
        printf("Selección de horario no válida.\n");
        return;
    }

    printf("Seleccione el tipo de entrada:\n");
    printf("1. Normal ($7)\n");
    printf("2. Estudiante ($3.5)\n");
    printf("3. Niño ($3)\n");
    scanf("%d", &tipoEntrada);
    getchar();  // Limpia el buffer de entrada

    if (tipoEntrada < 1 || tipoEntrada > 3) {
        printf("Tipo de entrada no válido.\n");
        return;
    }

    printf("Ingrese el nombre del cliente: ");
    fgets(nombreCliente, MAX_LONGITUD, stdin);
    nombreCliente[strcspn(nombreCliente, "\n")] = 0;  // Elimina el salto de línea

    snprintf(reservas[*numCompras][0], MAX_LONGITUD, "%s", nombreCliente);
    snprintf(reservas[*numCompras][1], MAX_LONGITUD, "%s", peliculas[peliculaSeleccionada][0]);
    snprintf(reservas[*numCompras][2], MAX_LONGITUD, "%s", horarios[peliculaSeleccionada][horarioSeleccionado]);

    (*numCompras)++;

    printf("Ticket comprado con éxito.\n");
}

void verCompras(char reservas[][3][MAX_LONGITUD], int numCompras) {
    if (numCompras == 0) {
        printf("No hay compras realizadas.\n");
        return;
    }

    printf("Compras realizadas:\n");
    for (int i = 0; i < numCompras; i++) {
        printf("%d. Cliente: %s, Película: %s, Horario: %s\n", i + 1, reservas[i][0], reservas[i][1], reservas[i][2]);
    }
}
