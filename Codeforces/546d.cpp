#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int n, a, b, ans, cont, t;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> a >> b;
        n = 1;
        while(a>b){
            n = n*a;
            a--;
        }
        cont = 2;
        ans = 0;
        while(n!=1){
            if(n%cont==0){
                n /= cont;
                ans++;
            }
            else 
                cont++;
            if(ans==0 && cont>sqrt(n)){
                ans = 1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
