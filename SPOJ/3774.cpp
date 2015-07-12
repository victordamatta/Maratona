//FATORIA2
#include <cstdio>

int fat(int x){
    if(x==0 || x==1) return 1;
    return x*fat(x-1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fat(n));
}
