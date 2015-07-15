#include <stdio.h>

int main() {
    int a,b,c,n,t=0;

    scanf("%d", &n);


    while (t < n) {
        scanf("%d %d %d", &a, &b, &c);

        if (a <= 20 && b <= 20 && c <= 20) printf("Case %d: good\n", t+1);
        else printf("Case %d: bad\n", t+1);

        t++;
    }


    return 0;

}
