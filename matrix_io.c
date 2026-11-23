#include <stdio.h>
#include "matrix_io.h"

int wczytajMacierz(
    const char *nazwaPliku,
    double macierz[MAX][MAX],
    int *wiersze,
    int *kolumny)
{

    FILE *plik;
    int i;
    int j;
    plik = fopen(nazwaPliku, "r");

    if (plik == NULL)
    {
        printf("Nie mozna otworzyc pliku '%s'.\n", nazwaPliku);
        return 1;
    }

    if (fscanf(plik, "%d %d", wiersze, kolumny) != 2)
    {
        printf("Nie udało się odczytac wymiarow z pliku'%s'.\n", nazwaPliku);
        fclose(plik);
        return 2;
    }
    if (*wiersze < 1 || *kolumny < 1 || *wiersze > MAX || *kolumny > MAX)
    {
        printf("Nieprawidłowe wymiary matrycy w pliku '%s'.\n", nazwaPliku);
        fclose(plik);
        return 3;
    }
    for (i = 0; i < *wiersze; i++)
    {
        for (j = 0; j < *kolumny; j++)
        {
            if (fscanf(plik, "%lf", &macierz[i][j]) != 1)
            {
                printf("Brakujący lub nieliczbowy element w pliku '%s'.\n", nazwaPliku);
                fclose(plik);
                return 4;
            }
        }
    }
    fclose(plik);
    return 0;
}


int zapiszMacierz(
    const char *nazwaPliku,
    double macierz[MAX][MAX],
    int wiersze,
    int kolumny)
{

    FILE *plik;
    int i;
    int j;
    plik = fopen(nazwaPliku, "w");

    if (plik == NULL)
    {
        printf("Nie mozna  utworzyc lub otworzyc pliku '%s' do zapisu.\n", nazwaPliku);
        return 6;
    }

    if (fprintf(plik, "%d %d\n", wiersze, kolumny) < 0)
    {
        printf("Nie udalo sie zapisac wymiarow do pliku '%s'.\n", nazwaPliku);
        fclose(plik);
        return 6;
    }
    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            if (j > 0)
            {
                fprintf(plik, " ");
            }
            if (fprintf(plik, "%.2f", macierz[i][j]) < 0)
            {
                printf("Nie udalo sie zapisac danych do pliku '%s'.\n ", nazwaPliku);
                fclose(plik);
                return 6;
            }
        }
        fprintf(plik, "\n");
    }

    if (fclose(plik) != 0)
    {
        printf("Blad podczas zamykania pliku '%s'.\n", nazwaPliku);
        return 6;
    }

    return 0;
}


void wyswietlMacierz(double macierz[MAX][MAX], int wiersze, int kolumny)
{
    int i;
    int j;

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            printf("%8.2f", macierz[i][j]);
        }
        printf("\n");
    }
}