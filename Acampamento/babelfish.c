#include <stdio.h>

long long int vet[1000005];

int main() {
    long long int i, t, n, aux, ans;
    scanf("%lld", &t);
    while(t--){
        for(i=0; i<1000004; i++){
            vet[i] = 0;
        }
        ans = 0;
        scanf("%lld", &n);
        while(n--){
            scanf("%lld", &aux);
            if(vet[aux]==0){
                ans++;
                vet[aux] = 1;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
