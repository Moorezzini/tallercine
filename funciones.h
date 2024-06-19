#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PELICULAS 10
#define MAX_CLIENTES 5
#define MAX_LONGITUD 40
#define MAX_HORARIOS 4

void ingresarCliente(char clientes[][2][MAX_LONGITUD], int *numClientes);
void verPeliculas(char peliculas[][4][MAX_LONGITUD], char horarios[][MAX_HORARIOS][MAX_LONGITUD], int numPeliculas);
void buscarPelicula(char peliculas[][4][MAX_LONGITUD], int numPeliculas);
void comprarTicket(char peliculas[][4][MAX_LONGITUD], char horarios[][MAX_HORARIOS][MAX_LONGITUD], float precios[], char reservas[][3][MAX_LONGITUD], int *numCompras);
void verCompras(char reservas[][3][MAX_LONGITUD], int numCompras);

#endif // FUNCIONES_H
