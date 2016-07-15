#include <cstdio>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
ll v[4000007];

int main(){
    int n;
    scanf ("%d", &n);
    int i = 0;
    f (n, j) {
        ll aux;
        scanf ("%I64d", &aux);
        v[i++] = aux;
    }
    sort (v, v+i);
    ll ans = -1;
    for (int k = 0; k < i-1; k += 2) {
        if (v[k+1] != v[k]) {
            ans = v[k];
        }
    }
    if (ans == -1) ans = v[i-1];
    printf ("%I64d\n", ans);
}
