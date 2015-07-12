#include <stdio.h>
int main(){
    int n, k, i, tn=0;
    long int tam[10005];
    long long int sum=0, hi, lo, mid;
    scanf("%d", &n);
    scanf("%d", &k);
    
    for(i=0; i<k; i++){
        scanf("%ld", &tam[i]);
        sum += tam[i];
    }
    
    sum /= n;
    lo = 1;
    hi = sum;
    while(hi!=lo){
        tn = 0;
        mid = lo + (hi-lo)/2;
        for(i=0; i<k; i++)
            tn += tam[i]/mid;
        if(tn<n)
            hi = mid-1;
        else
            lo = mid;
    }
    printf("%lld\n", mid);
    return 0;
}
