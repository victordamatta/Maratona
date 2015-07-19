#include <stdio.h>
#include <math.h>

typedef struct {
    int dia, altura;
} pair;

int abs(int a) { return a < 0 ? -a : a; }
int mmax(int a, int b) { return a > b ? a : b; }

int main() {
    int n, m, t = 0, max = 0, aux, b1, b2, a1, a2;
    double x;
    pair v[10010];

    scanf("%d %d", &n, &m);

    while (t < m) {
        scanf("%d %d", &v[t].dia, &v[t].altura);

        if (t > 0 && abs((v[t].altura - v[t-1].altura)/(v[t].dia - v[t-1].dia)) > 1) {
            printf("IMPOSSIBLE\n");
            return 0;

        } else if (t > 0) {
            a1 = v[t-1].altura;
            a2 = v[t].altura;
            b1 = v[t-1].dia;
            b2 = v[t].dia;

            if (a1 < a2) {
                a1 += (a2 - a1);
                b1 += (a2 - a1);
            
            } else if (a2 > a1) {
                a2 += (a1 - a2);
                b1 += (a1 - a2);

            }

            if (b2 == b1) aux = a1;
            else aux = a1 + (b2-b1)/2;

            if (aux > max) max = aux;
        }

        t++;
    }

    printf("%d\n", max);

    return 0;
}
