
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

inline ll ceil(ll x, ll y) { return x / y + (x % y != 0); }

int main(){
    std::ios::sync_with_stdio(false);
    ll k, d, t;
    cin >> k >> d >> t;
    t *= 2;
    ll r = d * ceil(k, d) - k;

    ll cycle = t / (2*k + r);
    t %= 2*k + r;
    ll ans = cycle * (k + r);

    if (t > 2*k) {
        t -= 2*k;
        ans += k + t;
        cout << ans << endl;
    }
    else {
        ans += t / 2;
        if (t % 2 == 0)
            cout << ans << endl;
        else
            cout << ans << ".5" << endl;
    }
}
