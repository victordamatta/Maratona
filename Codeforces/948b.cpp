
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
const int  N = 1000004;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

int main(){
    std::ios::sync_with_stdio(false);
    vector<ll> divs(N, 0);
    for(ll i = 2; i < N; i++) {
        if(divs[i]) continue;
        divs[i] = i;
        for(ll j = i*i; j < N; j += i) {
            divs[j] = i;
        }
    }

    ll ans = OO;
    ll x2;
    cin >> x2;
    ll copy = x2;
    while(copy != 1) {
        ll p = divs[copy];
        copy /= p;
        ll d = x2 / p;

        for(ll i = p*(d - 1) + 1; i <= p*d; i++) {
            if(i == divs[i]) continue;
            ll copy2 = i;
            while(copy2 != 1) {
                ll p2 = divs[copy2];
                copy2 /= p2;
                ll d2 = i / p2;
                ans = min(ans, p2*(d2 - 1) + 1);
            }
        }
    }
    cout << ans << endl;
}
