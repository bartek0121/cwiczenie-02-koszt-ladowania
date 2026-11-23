#define MATRIX_IO_H
#include "matrix.h"

int wczytajMacierz(
    const char *nazwaPliku,
    double macierz[MAX][MAX],
    int *wiersze,
    int *kolumny);

int zapiszMacierz(
    const char *nazwaPliku,
    double macierz[MAX][MAX],
    int wiersze,
    int kolumny);

void wyswietlMacierz(
    double macierz[MAX][MAX],
     int wiersze,
      int kolumny);