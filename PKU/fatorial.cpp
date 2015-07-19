#include <stdio.h>



int main() {
    long long int n, no_zeros;
    long long int x;

    scanf("%d", &n);

    while(n--) {
        scanf("%lld", &x);

        no_zeros = 0;
        while (x > 0) {
            no_zeros += x / 5;
            x/=5;
        }

        printf("%lld\n", no_zeros);
    }

    return 0;
}
