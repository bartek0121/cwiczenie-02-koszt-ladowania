#include <stdio.h>
#define MAX 4

int wczytajMAcierz(
    const char *nazwaPliku,
    int macierz[MAX][MAX],
    int *wiersze,
    int *kolumny)
{

    FILE *plik;
    plik = fopen(nazwaPliku, "r");

    if (plik == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 0;
    }

    if (fscanf(plik, "%d %d", wiersze, kolumny) != 2)
    {
        printf("Blad odczytu wymiarów\n");
        fclose(plik);
        return 0;
    }
    if (*wiersze <= 0 || *kolumny <= 0 || *wiersze > MAX || *kolumny > MAX)
    {
        printf("Nieprawidłowe wymiary matrycy\n");
        fclose(plik);
        return 0;
    }
    for (int i = 0; i < *wiersze; i = i + 1)
    {
        for (int j = 0; j < *kolumny; j = j + 1)
        {
            if (fscanf(plik, "%d", &macierz[i][j]) != 1)
            {
                fclose(plik);
                return 0;
            }
        }
    }
    fclose(plik);
    return 1;
}

void dodajMacierze(
    int A[MAX][MAX],
    int B[MAX][MAX],
    int C[MAX][MAX],
    int wiersze,
    int kolumny)
{
    for (int i = 0; i < wiersze; i = i + 1)
    {
        for (int j = 0; j < kolumny; j = j + 1)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void odejmijMacierze(
    int A[MAX][MAX],
    int B[MAX][MAX],
    int C[MAX][MAX],
    int wiersze,
    int kolumny)
{
    for (int i = 0; i < wiersze; i = i + 1)
    {
        for (int j = 0; j < kolumny; j = j + 1)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void wyswietlMacierz(
    int macierz[MAX][MAX],
    int wiersze,
    int kolumny)
{
    for (int i = 0; i < wiersze; i = i + 1)
    {
        for (int j = 0; j < kolumny; j = j + 1)
        {
            printf("%4d", macierz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];
    int wierszeA;
    int kolumnyA;
    int wierszeB;
    int kolumnyB;
    int wybor;

    if (!wczytajMAcierz("matrix1.txt", A, &wierszeA, &kolumnyA))
    {
        return 1;
    }

    if (!wczytajMAcierz("matrix2.txt", B, &wierszeB, &kolumnyB))
    {
        return 1;
    }

    printf("Wybierz dzialanie:\n");
    printf("1.Dodawanie \n");
    printf("2.Odejmowanie \n");
    if (scanf("%d", &wybor) != 1)
    {
        printf("Nieprawidlowe dane\n");
        return 1;
    }
    switch (wybor)
    {
    case 1:
        if (wierszeA == wierszeB && kolumnyA == kolumnyB)
        {
            dodajMacierze(A, B, C, wierszeA, kolumnyA);
            printf("\nWynik dodawania:\n");
            wyswietlMacierz(C, wierszeA, kolumnyA);
        }
        else
        {
            printf("\nNie mozna dodac tych macierzy\n");
        }
        break;

    case 2:
        if (wierszeA == wierszeB && kolumnyA == kolumnyB)
        {
            odejmijMacierze(A, B, C, wierszeA, kolumnyA);
            printf("\nWynik odejmowania:\n");
            wyswietlMacierz(C, wierszeA, kolumnyA);
        }
        else
        {
            printf("\nNie mozna odjac tych macierzy\n");
        }
        break;

    default:
        printf("\nNieprawidlowy wybor\n");
        break;
    }

    return 0;
}
