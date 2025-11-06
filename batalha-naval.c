#include <stdio.h>

#define linhas 10
#define colunas 10

int main(void) {
    int matriz[linhas][colunas];
    int i, j, k;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 0;
        }
    }


    {
        int navioH[3] = {3, 3, 3};
        int linhaH = 2, colunaH = 0;
        int podeH = 1;

        if (!(linhaH >= 0 && linhaH < linhas && colunaH >= 0 && colunaH + 3 <= colunas)) {
            podeH = 0;
        }

        if (podeH == 1) {
            for (k = 0; k < 3; k++) {
                if (matriz[linhaH][colunaH + k] != 0) {
                    podeH = 0;
                    break;
                }
            }
        }

        if (podeH == 1) {
            for (k = 0; k < 3; k++) {
                matriz[linhaH][colunaH + k] = navioH[k];
            }
        }
    }


    {
        int navioV[3] = {3, 3, 3};
        int linhaV = 0, colunaV = 3;
        int podeV = 1;

        if (linhaV < 0 || linhaV + 3 > linhas || colunaV < 0 || colunaV >= colunas) {
            podeV = 0;
        }

        if (podeV == 1) {
            for (k = 0; k < 3; k++) {
                if (matriz[linhaV + k][colunaV] != 0) {
                    podeV = 0;
                    break;
                }
            }
        }

        if (podeV == 1) {
            for (k = 0; k < 3; k++) {
                matriz[linhaV + k][colunaV] = navioV[k];
            }
        }
    }


    {
        int navioD1[3] = {3, 3, 3};
        int linhaD1 = 4, colunaD1 = 4;
        int podeD1 = 1;

        if (!(linhaD1 >= 0 && linhaD1 <= 7 && colunaD1 >= 0 && colunaD1 <= 7)) {
            podeD1 = 0;
        }

        if (podeD1 == 1) {
            for (k = 0; k < 3; k++) {
                if (matriz[linhaD1 + k][colunaD1 + k] != 0) {
                    podeD1 = 0;
                    break;
                }
            }
        }

        if (podeD1 == 1) {
            for (k = 0; k < 3; k++) {
                matriz[linhaD1 + k][colunaD1 + k] = navioD1[k];
            }
        }
    }

   
    {
        int navioD2[3] = {3, 3, 3};
        int linhaD2 = 7, colunaD2 = 2;
        int podeD2 = 1;

        if (!(linhaD2 >= 0 && linhaD2 <= 7 && colunaD2 >= 2 && colunaD2 < colunas)) {
            podeD2 = 0;
        }

        if (podeD2 == 1) {
            for (k = 0; k < 3; k++) {
                if (matriz[linhaD2 + k][colunaD2 - k] != 0) {
                    podeD2 = 0;
                    break;
                }
            }
        }

        if (podeD2 == 1) {
            for (k = 0; k < 3; k++) {
                matriz[linhaD2 + k][colunaD2 - k] = navioD2[k];
            }
        }
    }

    int S = 5;
    int mid = S / 2;
    int cone[5][5], cruz[5][5], octa[5][5];

    for (i = 0; i < S; i++) {
        for (j = 0; j < S; j++) {
            int dj = j - mid;
            if (dj < 0) dj = -dj;       
            if (dj <= i) cone[i][j] = 1;
            else         cone[i][j] = 0;
        }
    }

    for (i = 0; i < S; i++) {
        for (j = 0; j < S; j++) {
            if (i == mid || j == mid) cruz[i][j] = 1;
            else                      cruz[i][j] = 0;
        }
    }

    for (i = 0; i < S; i++) {
        for (j = 0; j < S; j++) {
            int di = i - mid; if (di < 0) di = -di;
            int dj = j - mid; if (dj < 0) dj = -dj;
            if (di + dj <= mid) octa[i][j] = 1;
            else                octa[i][j] = 0;
        }
    }

    
    printf("\nHabilidade: CONE (5x5)\n");
    printf("    "); for (j = 0; j < S; j++) printf("%2d ", j); printf("\n   ");
    for (j = 0; j < S; j++) printf("---"); printf("-\n");
    for (i = 0; i < S; i++) {
        printf("%2d |", i);
        for (j = 0; j < S; j++) printf("%2d ", cone[i][j]);
        printf("\n");
    }

    printf("\nHabilidade: CRUZ (5x5)\n");
    printf("    "); for (j = 0; j < S; j++) printf("%2d ", j); printf("\n   ");
    for (j = 0; j < S; j++) printf("---"); printf("-\n");
    for (i = 0; i < S; i++) {
        printf("%2d |", i);
        for (j = 0; j < S; j++) printf("%2d ", cruz[i][j]);
        printf("\n");
    }

    printf("\nHabilidade: OCTAEDRO (5x5)\n");
    printf("    "); for (j = 0; j < S; j++) printf("%2d ", j); printf("\n   ");
    for (j = 0; j < S; j++) printf("---"); printf("-\n");
    for (i = 0; i < S; i++) {
        printf("%2d |", i);
        for (j = 0; j < S; j++) printf("%2d ", octa[i][j]);
        printf("\n");
    }


    {
        int r0_cruz = 5, c0_cruz = 4; 
        for (i = 0; i < S; i++) {
            for (j = 0; j < S; j++) {
                if (cruz[i][j] == 1) {
                    int r = r0_cruz + (i - mid);
                    int c = c0_cruz + (j - mid);
                    if (r >= 0 && r < linhas && c >= 0 && c < colunas) {
                        if (matriz[r][c] == 0) matriz[r][c] = 5;
                    }
                }
            }
        }
    }

    printf("\nTABULEIRO 10x10\n");
    printf("    ");
    for (j = 0; j < colunas; j++) printf("%2d ", j);
    printf("\n   ");
    for (j = 0; j < colunas; j++) printf("---");
    printf("-\n");
    for (i = 0; i < linhas; i++) {
        printf("%2d |", i);
        for (j = 0; j < colunas; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}