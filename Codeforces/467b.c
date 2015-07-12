#include <stdio.h>

long int power(int base, int exp){
    if(exp==0) return 1;
    else return base*power(base, exp-1);
}

void tob(long int num, int * vet, int n){
    int i;
    for(i=n-1; i>=0; i--){
        vet[i] = num/power(2, i);
        num = num%power(2, i);
    }
}

int difb(int * v1, int * v2, int size){
    int i, ans=0;
    for(i=0; i<size; i++){
        if(v1[i]!=v2[i])
            ans++;
    }
    return ans;
}

int main(){
    int n, m, k, p[1500][30], i, ans;
    long int num;
    scanf("%d%d%d", &n, &m, &k);
    if(k==n)
        printf("%d\n", m);
    else{
        ans = 0;
        for(i=0; i<=m; i++){
            scanf("%ld", &num);
            tob(num, p[i], n);
        }
        for(i=0; i<m; i++){
            if(difb(p[i], p[m], n)<=k)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
