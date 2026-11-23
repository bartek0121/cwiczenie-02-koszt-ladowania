#include <stdio.h>
#include "matrix_io.h"
#include "matrix.h"
#define MAX_NAZWA 256

int main(void)
{
    double A[MAX][MAX];
    int wierszeA;
    int kolumnyA;
    double B[MAX][MAX];
    int wierszeB;
    int kolumnyB;
    double C[MAX][MAX];
    int wierszeC;
    int kolumnyC;
    int status;
    int wybor;
    char nazwaA[MAX_NAZWA];
    char nazwaB[MAX_NAZWA];
    char nazwaWynik[MAX_NAZWA];

    printf("KALKULATOR MACIERZY\n");
    printf("Podaj nazwe pliku z macierza A: ");
    if (scanf("%255s", nazwaA) !=1)
    {
        printf("Nieprawidlowa nazwa pliku A.\n");
        return 7;
    }

    printf("Podaj nazwe pliku z macierza B: ");
    if (scanf("%255s", nazwaB) !=1)
    {
        printf("Nieprawidlowa nazwa pliku B.\n");
        return 7;
    }

    printf("Podaj nazwe pliku wynikowego: ");
    if (scanf("%255s", nazwaWynik) !=1)
    {
        printf("Nieprawidlowa nazwa pliku wynikowego.\n");
        return 7;
    }

    printf("\nWybierz operacje:\n");
    printf("1. Dodawanie (A + B)\n");
    printf("2. Odejmowanie (A - B)\n");
    printf("3. Mnozenie (A * B)\n");
    printf("Twoj wybor: ");
    if (scanf("%d", &wybor) != 1)
    {
        printf("Wyborem operacji musi byc liczba (1, 2 lub 3).\n");
        return 7;
    }

    status = wczytajMacierz(nazwaA, A, &wierszeA, &kolumnyA);
    if (status != 0)
    {
        return status;
    }

    status = wczytajMacierz(nazwaB, B, &wierszeB, &kolumnyB);
    if (status != 0)
    {
        return status;
    }

    switch (wybor)
    {
        case 1:
        status = dodajMacierze(A, wierszeA, kolumnyA, B, wierszeB, kolumnyB, C, &wierszeC, &kolumnyC);
        break;

        case 2:
        status = odejmijMacierze(A, wierszeA, kolumnyA, B, wierszeB, kolumnyB, C, &wierszeC, &kolumnyC);
        break;

        case 3:
        status = pomnozMacierze(A, wierszeA, kolumnyA, B, wierszeB, kolumnyB, C, &wierszeC, &kolumnyC);
        break;

        default:
        printf("Nieznana opcja w menu (wybierz 1, 2 lub 3).\n");
        return 7;
    }

    if (status != 0)
    {
        return status;
    }

    status = zapiszMacierz(nazwaWynik,C, wierszeC, kolumnyC);
    if (status != 0)
    {
        return status;
    }

    printf("\n Wynik (%d x %d) zapisano do pliku '%s':\n", wierszeC, kolumnyC, nazwaWynik);
    wyswietlMacierz(C, wierszeC, kolumnyC);

    

    return 0;
}
