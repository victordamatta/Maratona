
#include <stdio.h>

using namespace std;

int factorial(int n);

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", factorial(n));

    return 0;
}

int factorial(int n){
    if(n==1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}
