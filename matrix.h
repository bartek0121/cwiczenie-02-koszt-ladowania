#define MATRIX_H
#define MAX 20

int dodajMacierze(
    double A[MAX][MAX], int wierszeA, int kolumnyA,
    double B[MAX][MAX], int wierszeB, int kolumnyB,
    double C[MAX][MAX], int *wierszeC, int *kolumnyC);

int odejmijMacierze(
    double A[MAX][MAX], int wierszeA, int kolumnyA,
    double B[MAX][MAX], int wierszeB, int kolumnyB,
    double C[MAX][MAX], int *wierszeC, int *kolumnyC);

int pomnozMacierze(
    double A[MAX][MAX], int wierszeA, int kolumnyA,
    double B[MAX][MAX], int wierszeB, int kolumnyB,
    double C[MAX][MAX], int *wierszeC, int *kolumnyC);