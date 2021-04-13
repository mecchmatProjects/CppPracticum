#include <stdio.h>
#include <stdlib.h>
#define N 
#define M 
#define K
int vvid(int matr[N][N], unsigned n, unsigned m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matr[i][j]);
        }
    }

}
void vyvid(int matr[N][M], unsigned n, unsigned m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matr[i][j]);

        }
        printf("\n");
    }
}


int dobutok(int matr1[N][M], int matr2[M][K], unsigned n, unsigned m, unsigned k) {
    double result[n][k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            result[i][j] = 0;
            for (int l = 0; l < m; l++) {
                result[i][j] += matr1[i][l] * matr2[l][j];
            }
        }
    }
    return result;
}


int main() {

    int matr1[N][M];
    int matr2[M][K];
    int result[N][K];
    int n, m, k;
    printf("input n,m,k");
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    vvid(matr1, n, m);
    vvid(matr2, m, k);

    result = dobutok(matr1, matr2, n, m, k);
    vyvid(result, n, k);

}
