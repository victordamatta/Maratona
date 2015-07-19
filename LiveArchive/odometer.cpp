#include <iostream>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long long int n, m, ans;
int d, aux;

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> n, n!=0){
        m = n;
        ans = 0;
        aux = 1;
        while(n!=0){
            d = n%10;
            n/=10;
            if(d<4) ans += d*aux;
            else ans += (d-1)*aux;
            aux*=9;
        }
        cout << m << ": " << ans << "\n";
    }
}
