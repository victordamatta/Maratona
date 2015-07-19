
#include <cstdio>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    long long int n, aux, v[10005], v2[10005], cont, k;
    scanf("%lld", &n);
    m = n;
    for(int i=0; i<n; i++){
        scanf("%lld", &v[i]);
    }
    sort(v, v+n);
    aux = 0;
    cont = 0;
    if(n!=0){
    k = 0;
    while((aux==0 || aux%n!=0) && k<=n){
        k++;
        aux = 0;
        cont = 0;
        for(int i=n-k; i>=0; i--){
            if(v[i]!=0){
                aux+=v[i];
                v2[cont] = v[i];
                cont++;
            }
        }
    }
    }
    if(k>n || n==0) printf("0\n");
    else{
        printf("%lld\n", cont);
        for(int i=0; i<cont; i++){
            printf("%lld\n", v2[i]);
        }
    }
}
