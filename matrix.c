#include <stdio.h>
#include "matrix.h"


int dodajMacierze(
    double A[MAX][MAX], int wierszeA, int kolumnyA,
    double B[MAX][MAX], int wierszeB, int kolumnyB,
    double C[MAX][MAX], int *wierszeC, int *kolumnyC)
{
    int i;
    int j;

    if (wierszeA != wierszeB || kolumnyA != kolumnyB)
    {
        printf("Do dodawania macierze musza miec identyczne wymiary.\n");
        return 5;
    }
    *wierszeC = wierszeA;
    *kolumnyC = kolumnyA;

    for (i = 0; i < *wierszeC; i++)
    {
        for (j = 0; j < *kolumnyC; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return 0;
}

int odejmijMacierze(
    double A[MAX][MAX], int wierszeA, int kolumnyA,
    double B[MAX][MAX], int wierszeB, int kolumnyB,
    double C[MAX][MAX], int *wierszeC, int *kolumnyC)
{
    int i;
    int j;

    if (wierszeA != wierszeB || kolumnyA != kolumnyB)
    {
        printf("Do odejmowania macierze musza miec identyczne wymiary.\n");
        return 5;
    }
    *wierszeC = wierszeA;
    *kolumnyC = kolumnyA;

    for (i = 0; i < *wierszeC; i++)
    {
        for (j = 0; j < *kolumnyC; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return 0;
}

int pomnozMacierze(
    double A[MAX][MAX], int wierszeA, int kolumnyA,
    double B[MAX][MAX], int wierszeB, int kolumnyB,
    double C[MAX][MAX], int *wierszeC, int *kolumnyC)
{
    int i;
    int j;
    int k;

    if (kolumnyA != wierszeB)
    {
        printf("Do mnozenia liczba kolumn w macierzy A musi byc rowna liczbie wierzy w macierzy B.\n");
        return 5;
    }
    *wierszeC = wierszeA;
    *kolumnyC = kolumnyB;

    for (i = 0; i < *wierszeC; i++)
    {
        for (j = 0; j < *kolumnyC; j++)
        {
            C[i][j] = 0.0;
            for (k = 0; k < kolumnyA; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return 0;
}

