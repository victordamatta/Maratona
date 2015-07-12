#include <bits/stdc++.h>
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, m, k;

int main(){
    scanf("%d%d", &n, &m);
    k=1;
    while(m>=k){
        m -= k;
        k++;
        if(k>n)
            k %= n;
    }
    printf("%d\n", m);
}
