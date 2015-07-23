#include <iostream>
#include <climits>
#include <math.h>
#include <algorithm>
/*
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    ll n, t;
    cin >> t;
    while(t--){
        ll x, y, aux, m = LLONG_MAX, mx, my;
        cin >> n;
        if(n==0){
            cout << "0 X 0 = 0\n";
            continue;
        }
        n = n%5==0 ? n/5 : n/5+1;
        x = sqrt(n) + 10;
        while(x >= 1){
            y = n%x==0 ? n/x : n/x+1;
            aux = (10*y + 2)*(44*x + 4);
            if(aux < m){
                m = aux;
                mx = x;
                my = y;
            }
            else if(aux==m){
                if(abs(10*y-44*x) < abs(10*my-44*mx)){
                    m = aux;
                    mx = x;
                    my = y;
                }
            }
            x--;
        }
        ll a, b;
        a = 4+44*mx;
        b = 2+10*my;
        if(a>b){
            cout << a << " X " << b << " = " << m << "\n";
        }
        else{
            cout << b << " X " << a << " = " << m << "\n";
        }
    }
}
