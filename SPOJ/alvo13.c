#include <stdio.h>
#define MAX 1000000

long long int bsearch(long long int hi, long long int lo, long long int target, long long int * vet){
    long long int mid = (hi+lo)/2;
    if(hi==lo) return hi;
    if(vet[mid]<target) return bsearch(hi, mid+1, target, vet);
    else return bsearch(mid, lo, target, vet);
}

int main(){
    long long int c, t, i, x, y;
    long long int r[MAX], d, ans=0;
    scanf("%lld %lld", &c, &t);
    for(i=0; i<c; i++){
        scanf("%lld", &r[i]);
        r[i] *= r[i];
    }
    for(i=0; i<t; i++){
        scanf("%lld %lld", &x, &y);
        d = x*x + y*y;
        if(r[c-1]>=d)
            ans += c - bsearch(c-1, 0, d, r); 
    }
    printf("%lld\n", ans);
    return 0;
}
