#include <stdio.h>

int main () {

   int tabuleiro[10][10];
   int i, j;

   for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
        tabuleiro[i][j] = 0; 
    }
}

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    int linhaH = 2, colH = 4;
    int linhaV = 6, colV = 1;

    int podeH = 1;

    if (linhaH < 0 || linhaH >= 10) podeH = 0;
    if (colH < 0 || colH + 3 > 10) podeH = 0;

    if (podeH == 1) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[linhaH][colH + j] != 0) {
                podeH = 0;
            }
        }
    }

    if (podeH == 1) {
        for (j = 0; j < 3; j++) {
            tabuleiro[linhaH][colH + j] = navioHorizontal[j];
        }
    }

    int podeV = 1;

    if (colV < 0 || colV >= 10) podeV = 0;
    if (linhaV < 0 || linhaV + 3 > 10) podeV = 0;

    if (podeV == 1) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colV] != 0) {
                podeV = 0;
            }
        }
    }
    
    if (podeV == 1) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colV] = navioVertical[i];
        }
    }

    printf("    ");
    for (j = 0; j < 10; j++) printf("%2d ", j);
    printf("\n");

    printf("   ");
    for (j = 0; j < 10; j++) printf("---");
    printf("-\n");

    for (i = 0; i < 10; i++) {
        printf("%2d |", i);
        for (j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
}

    return 0;
}