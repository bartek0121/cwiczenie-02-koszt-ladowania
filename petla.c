#include <stdio.h>
#define MAX 20
int main(void) {
    int wA = 2, kA = 3, wB = 2, kB = 3, wC = 2, kC = 3;
   
    int i, j;
   double A[MAX][MAX] = { {1, 2, 3}, {4, 5, 6}};
   double B[MAX][MAX] = { {7, 8, 9}, {10, 11, 12}};
   double C[MAX][MAX];
   
   
   printf("Suma A + B:\n");
   
   for (i = 0; i < wA; i++) {
      for (j = 0; j < kA; j++) {
        C[i][j] = A[i][j] + B[i][j];
         printf("%8.2f ", C[i][j]);
         
      }
      printf("\n");


      printf("Roznica  A -  B :\n");
   
   for (i = 0; i < wB; i++) {
      for (j = 0; j < kB; j++) {
        C[i][j] = A[i][j] - B[i][j];
         printf("%8.2f ", C[i][j]);
         
      }
      printf("\n");
    }
    return 0;
}
}
