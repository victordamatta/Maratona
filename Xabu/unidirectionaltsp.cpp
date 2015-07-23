#include <iostream>
#include <cstring>
#include <cstdio>
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define OO 2147483648
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

ll n, m, mat[15][107];
ll vpd[15][107];
ll choices[107];

ll mod(ll a, ll b){
    if(a>=0) return a%b;
    else return a%b+b;
}

ll pd(ll i, ll j){
    if(j==m) return 0;
    if(vpd[i][j]!=OO) return vpd[i][j];

    vpd[i][j] = mat[i][j] + min(pd(mod(i+1, n), j+1), min(pd(mod(i-1, n), j+1), pd(i, j+1)));

    return vpd[i][j];
}

void pd2(ll i, ll j){
    if(j==m-1) return;

    ll a, b, c;
    ll x, y;
    x = mod(i+1, n);
    y = mod(i-1, n);
    a = mat[i][j] + pd(x, j+1);
    b = mat[i][j] + pd(y, j+1);
    c = mat[i][j] + pd(i, j+1);
    
    ll aux;
    if(a < b && a < c)
        aux = x;
    else if(b < a && b < c)
        aux = y;
    else if(c < a && c < b)
        aux = i;
    else if(a<c && a==b)
        aux = min(x, y);
    else if(a<b && a==c)
        aux = min(x, i);
    else if(b<a && b==c)
        aux = min(y, i);
    else
        aux = min(y, min(x, i));

    choices[j] = aux;
    pd2(aux, j+1);
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin.peek()!=EOF){
        cin >> n >> m;
        f(15, i){
            f(107, j){
                vpd[i][j] = OO;
            }
        }
        f(n, i){
            f(m, j){
                cin >> mat[i][j];
            }
        }
        ll ans = pd(0, 0);
        pd2(0, 0);
        cout << "1";
        f(m-1, i){
            cout << " " << choices[i]+1;
        }
        cout << "\n";
        cout << ans << "\n";
        cin.get();
    }
}
