#include <iostream>
#include <math.h>
#include <map>
using namespace std;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long long int n, aux, aux2; 
long long int ans;
map<long int, long long int> m;

long int power(int a, int b){
    long int ans = 1;
    while(b--){
        ans*=a;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    ans = 0;
    m[1] = 0;
    m[2] = 9;
    m[3] = 189;
    m[4] = 2889;
    m[5] = 38889;
    m[6] = 488889;
    m[7] = 5888889;
    m[8] = 68888889;
    m[9] = 788888889;
    m[10]= 8888888889;

    for(int i=10; i>0; i--){
        aux = power(10, i-1);
        aux2 = n/aux;
        if(aux2>0){
            ans = i*(aux2-1)*aux;
            aux2 = n%aux;
            ans+=(aux2+1)*i;
            ans+=m[i];
            break;
        }
    }
    cout << ans << "\n";
}
