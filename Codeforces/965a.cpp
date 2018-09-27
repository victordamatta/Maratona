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
    ll k, n, s, p;
    cin >> k >> n >> s >> p;
    ll per_person = (n + s - 1) / s;
    ll overall = k * per_person;
    ll ans = (overall + p - 1) / p;
    cout << ans << endl;
}
