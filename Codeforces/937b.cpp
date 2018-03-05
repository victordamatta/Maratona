
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 10004;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

ll small_divisor(ll x) {
    ll d = 2;
    while (d * d <= x) {
        if (x % d == 0) return d;
        d++;
    }
    return x;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll p, y;
    cin >> p >> y;
    while (small_divisor(y) <= p && y > p) y--;
    if (y == p)
        cout << -1 << endl;
    else
        cout << y << endl;
}
