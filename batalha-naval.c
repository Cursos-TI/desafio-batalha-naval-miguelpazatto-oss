#include <stdio.h>

#define linhas 10
#define colunas 10

int main () {

    int matriz[linhas][colunas];
      int i, j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
            
    int navioH[3] = {3, 3, 3};

    int linhaH = 2, colunaH = 0;
    int podeH;

    podeH = 1;

    if (!(linhaH >= 0 && linhaH < linhas && colunaH >= 0 && colunaH + 3 <= colunas)) {
        podeH = 0;
    }

    if (podeH == 1) {
        for (int k = 0; k < 3; k++) {
            if (matriz[linhaH][colunaH + k] != 0) {
                podeH = 0;
                break;  // k é o tamanho do navio, se k achar algo diferente de 0 quebra.
            }
        }
    }

    if (podeH == 1) {
        for (int k = 0; k < 3; k++) {
            matriz[linhaH][colunaH + k] = navioH[k];
        }
    }



    int navioV[3] = {3, 3, 3};

    int linhaV = 0, colunaV = 3;
    int podeV;

    podeV = 1;

    if (linhaV < 0 && linhaV + 3 > linhas && colunaV < 0 && colunaV > colunas) {
        podeH = 0;
    }
   
    if (podeH == 1) {
        for(int k = 0; k < 3; k++) {
            if (matriz[linhaV + k][colunaV] != 0) {
                podeH = 0;
                break; 
            }
        }
    }

    if (podeH == 1) {
        for(int k = 0; k < 3; k++) {
            matriz[linhaV + k][colunaV] = navioV[k];
        }
    }


    int navioD1[3] = {3, 3, 3};

    int linhaD1 = 4, colunaD1 = 4;
    int podeD1;

    podeD1 = 1;

    if (!(linhaD1 >= 0 && linhaD1 <= 7 && colunaD1 >= 0 && colunaD1 <= 7)) {
        podeD1 = 0;
    }

    if (podeD1 == 1) {
        for(int k = 0; k < 3; k++) {
            if (matriz[linhaD1 + k][colunaD1 + k] != 0) {
                podeD1 = 0;
                break;
            }
        }
    }

    if (podeD1 == 1) {
        for(int k = 0; k < 3; k++) {
            matriz[linhaD1 + k][colunaD1 + k] = navioD1[k];
        }
    }
}


    int navioD2[3] = {3, 3, 3};

    int linhaD2 = 7, colunaD2 = 2;
    int podeD2;

    podeD2 = 1;

    if (!(linhaD2 >= 0 && linhaD2 <= 7 && colunaD2 >= 2 && colunaD2 <= 7)) {
        podeD2 = 0;
    }

    if (podeD2 == 1) {
        for(int k = 0; k < 3; k++) {
            if (matriz[linhaD2][9 - linhaD2] != 0) {
                podeD2 = 0;
                break;
            }
        }
    }

    if (podeD2 == 1) {
        for(int k = 0; k < 3; k++) {
            matriz[linhaD2 + k][colunaD2 - k] = navioD2[k];
        }
    }


    printf("  ");
    for(int a = 0; a < 10; a++) {
        printf("%d ", a);
    }
    printf("\n");

    printf("  ");
    for(int a = 0; a < 10; a++) {
        printf("---");
    }
    printf("\n");

    for(int b = 0; b < 10; b++) {
        printf("%d ", b);
        for(int a = 0; a < 10; a++) {
            printf("%d ", matriz[b][a]);
        }
        printf("\n");

    }

    return 0;
}