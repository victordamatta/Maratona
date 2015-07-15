#include <stdio.h>
int main(){
    long long int a, b, cont;
    a=3; b=2;
    while(b<10000000){
        a = a*b;
        b = a+1;
        printf("%lld\n", b);
        cont++;
    }
    printf("%lld\n", cont);
}
