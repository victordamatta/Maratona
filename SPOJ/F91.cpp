#include <cstdio>

int f91(int x){
    if(x>=101) return x-10;
    return f91(f91(x+11));
}

int main(){
    int n;
    while(scanf("%d", &n), n){
        printf("f91(%d) = %d\n", n, f91(n));
    }
}
