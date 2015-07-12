
#include <stdio.h>

using namespace std;

bool eh_perfeito(int n);

int main(){
    int n, m;
    scanf("%d", &m);
    while(scanf("%d", &n)!=EOF){
        if (eh_perfeito(n)){
            printf("%d eh perfeito\n", n);
        } else {
            printf("%d nao eh perfeito\n", n);
        }
    }

    return 0;
}

bool eh_perfeito(int n){
    int sum=0;

    for (int j=1; j<n; j++){
        if (n%j==0){
            sum+=j;
        }
    }

    if (sum==n){return true;}else{return false;}
}
