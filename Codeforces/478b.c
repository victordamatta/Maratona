#include <stdio.h>

long long int set(long long int x){
    return x*(x-1)/2;
}

int main(){
    long long int n, m, min, max, num;
    scanf("%lld %lld", &n, &m);
    max = set(n-(m-1));
    num = n%m;
    if(num==0)
        min = m*set(n/m);
    else{
        min = num*set((n/m)+1) + (m-num)*set(n/m);
    }
    printf("%lld %lld\n", min, max);
    return 0;
}
