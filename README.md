# Kalkulator Macierzy (C90)

Program konsolowy napisany w standardzie **ANSI C (C90)**, umożliwiający wykonywanie podstawowych operacji na macierzach wczytywanych z plików tekstowych oraz zapis wyników do pliku.

## Funkcje

* **Dodawanie macierzy** (`A + B`)
* **Odejmowanie macierzy** (`A - B`)
* **Mnożenie macierzy** (`A * B`)
* Obsługa macierzy prostokątnych i kwadratowych o wymiarach od `1 x 1` do `20 x 20` (`MAX = 20`)
* Walidacja danych wejściowych, wymiarów oraz obsługa błędów za pomocą dedykowanych kodów wyjścia

---

## Struktura projektu

* `main.c` – interfejs użytkownika, obsługa menu i przepływ sterowania programu
* `matrix.h`, `matrix.c` – logika operacji matematycznych na macierzach (dodawanie, odejmowanie, mnożenie)
* `matrix_io.h`, `matrix_io.c` – obsługa operacji wejścia/wyjścia (wczytywanie z pliku, zapis do pliku, wyświetlanie w konsoli)
* `Makefile` – automatyzacja kompilacji i czyszczenia projektu
* `.gitignore` – wykluczenie plików binarnych (`.o`, `.exe`) oraz tymczasowych plików wynikowych z repozytorium
* `A_*.txt`, `B_*.txt`, `C_*.txt`, `bad_*.txt`, `incomplete.txt` – zestaw plików testowych

---

## Kompilacja i uruchomienie

Projekt kompilowany jest z restrykcyjnymi flagami zgodności ze standardem C90:
`-std=c90 -Wall -Wextra -Werror -pedantic`

* **Kompilacja:**
  ```bash
  make
  ```
* **Kompilacja i natychmiastowe uruchomienie:**
  ```bash
  make run
  ```
* **Usunięcie plików obiektowych i wykonywalnych:**
  ```bash
  make clean
  ```



## Kody wyjścia programu

| Kod | Znaczenie |
| :-: | :--- |
| **`0`** | Poprawne wykonanie programu i zapis wyniku |
| **`1`** | Nie udało się otworzyć pliku wejściowego (np. brak pliku) |
| **`2`** | Błąd odczytu wymiarów macierzy z nagłówka pliku |
| **`3`** | Wymiary macierzy poza dozwolonym zakresem (`< 1` lub `> 20`) |
| **`4`** | Brakujące lub nieliczbowe dane wewnątrz pliku macierzy |
| **`5`** | Niezgodne wymiary macierzy dla wybranej operacji |
| **`6`** | Błąd tworzenia, zapisu lub zamknięcia pliku wynikowego |
| **`7`** | Błędne dane wprowadzone przez użytkownika w konsoli / nieznana opcja menu |

---

## Dokumentacja testów (niezależne obliczenia)

W repozytorium znajdują się pliki testowe weryfikujące wszystkie wymagane przypadki brzegowe oraz obsługę błędów.

### 1. Testy poprawnych obliczeń (kod wyjścia `0`)

#### A. Macierze prostokątne (`2 x 3`), zera i liczby ujemne – Dodawanie i Odejmowanie
* **Dane wejściowe:**
  * `A_rect.txt` (`2 x 3`):
    ```text
     0  -2   4.5
    -1   3   0
    ```
  * `B_rect.txt` (`2 x 3`):
    ```text
     5  -3  -4.5
     1   0  -2
    ```
* **Niezależne obliczenia:**
  * **Dodawanie (`A + B`):**
    * Wiersz 1: `[0 + 5, -2 + (-3), 4.5 + (-4.5)] = [5.00, -5.00, 0.00]`
    * Wiersz 2: `[-1 + 1, 3 + 0, 0 + (-2)] = [0.00, 3.00, -2.00]`
  * **Odejmowanie (`A - B`):**
    * Wiersz 1: `[0 - 5, -2 - (-3), 4.5 - (-4.5)] = [-5.00, 1.00, 9.00]`
    * Wiersz 2: `[-1 - 1, 3 - 0, 0 - (-2)] = [-2.00, 3.00, 2.00]`

#### B. Macierze prostokątne (`2 x 3` oraz `3 x 2`) – Mnożenie
* **Dane wejściowe:**
  * `A_rect.txt` (`2 x 3`):
    ```text
     0  -2   4.5
    -1   3   0
    ```
  * `C_rect.txt` (`3 x 2`):
    ```text
     2   0
    -1   4
     0  -2
    ```
* **Niezależne obliczenia (`A * C` -> macierz `2 x 2`):**
  * `c[1][1] = 0 * 2 + (-2) * (-1) + 4.5 * 0 = 0 + 2 + 0 = 2.00`
  * `c[1][2] = 0 * 0 + (-2) * 4 + 4.5 * (-2) = 0 - 8 - 9 = -17.00`
  * `c[2][1] = (-1) * 2 + 3 * (-1) + 0 * 0 = -2 - 3 + 0 = -5.00`
  * `c[2][2] = (-1) * 0 + 3 * 4 + 0 * (-2) = 0 + 12 + 0 = 12.00`
  * **Oczekiwany wynik:**
    ```text
    2 2
    2.00 -17.00
    -5.00 12.00
    ```

#### C. Macierze `1 x 1` (wszystkie operacje)
* **Dane wejściowe:** `A_1x1.txt` = `[-3.5]`, `B_1x1.txt` = `[2]`
* **Niezależne obliczenia i oczekiwane wyniki:**
  * Dodawanie: `-3.5 + 2 = -1.50`
  * Odejmowanie: `-3.5 - 2 = -5.50`
  * Mnożenie: `(-3.5) * 2 = -7.00`

#### D. Maksymalny limit wymiarów (`20 x 20`)
* **Dane wejściowe:** `A_20.txt` (macierz `20 x 20` wypełniona wartościami `1`) oraz `B_20.txt` (macierz `20 x 20` wypełniona wartościami `2`).
* **Niezależne obliczenia (`A_20 * B_20`):**
  * Każdy element macierzy wynikowej to suma 20 iloczynów `1 * 2`:
    `c[i][j] = 20 * (1 * 2) = 40.00`
* **Oczekiwany wynik:** Macierz `20 x 20` wypełniona w całości wartością `40.00`.

---

### 2. Testy obsługi błędów

| Przypadek testowy | Pliki / Wejście | Oczekiwany kod wyjścia |
| :--- | :--- | :---: |
| Brak pliku wejściowego | Podanie nazwy nieistniejącego pliku (np. `brak.txt`) | **`1`** |
| Błędny nagłówek pliku | `bad_header.txt` (tekst `abc def` zamiast wymiarów) | **`2`** |
| Wymiar poniżej minimum | `bad_dim0.txt` (wymiar `0 3`) | **`3`** |
| Przekroczenie limitu `MAX` | `bad_dim21.txt` (wymiar `21 20`) | **`3`** |
| Niepełne dane w pliku | `incomplete.txt` (nagłówek `2 3`, podane tylko 4 liczby) | **`4`** |
| Błędne (nieliczbowe) dane | `bad_data.txt` (tekst `xyz` zamiast liczby) | **`4`** |
| Niezgodne wymiary (dodawanie) | `A_rect.txt` (`2 x 3`) i `C_rect.txt` (`3 x 2`), operacja `1` | **`5`** |
| Niezgodne wymiary (mnożenie) | `A_rect.txt` (`2 x 3`) i `B_rect.txt` (`2 x 3`), operacja `3` | **`5`** |
| Nieprawidłowy wybór w menu | Poprawne pliki, wybór operacji spoza zakresu `1–3` | **`7`** |