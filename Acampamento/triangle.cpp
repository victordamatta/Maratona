#include <stdio.h>

int estados[110][110][110];
int m[110][110];

int max(int a, int b) { return a > b ? a : b; }

int r(int a, int am, int i) {
    int aux1, aux2;
    
    if (estados[a][am][i] != -1) return estados[a][am][i];
    else if (a == am) return m[a][i];
    else {
        aux1 = r(a+1, am, i);
        aux2 = r(a+1, am, i+1);

        estados[a][am][i] = max(aux1, aux2) + m[a][i];
        
        return estados[a][am][i];
    }
}

int main() {
    int n, i, j, k;

    scanf("%d", &n);
    for(i = 0; i < 110; i++) {
        for(j = 0; j < 110; j++) {
            for (k = 0; k < 110; k++) {
                estados[i][j][k] = -1;
            }

            if (j <= i && i < n) scanf("%d", &m[i][j]);
        }
    }

    printf("%d\n", r(0, n-1, 0));

    return 0;
}
