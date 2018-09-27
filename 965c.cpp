
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

int main(){
    std::ios::sync_with_stdio(false);
    ll n, k, m, d;
    cin >> n >> k >> m >> d;
    ll ans = m;
    ll lo = 1;
    ll hi = m;
    for(int i = 1; i < d; i++) {
        ll lo = 1;
        ll hi = m;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            if(lo == mid) break;

            if(mid > n/(k*i)) hi = mid-1;
            else lo = mid;
        }
        if(n - lo*k*i >= lo) ans = max(ans, lo*(i+1));
        else ans = max(ans, lo*i);
    }
    cout << ans << endl;
}
