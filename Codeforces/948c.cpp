
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

vector<ll> snow;
vector<ll> temp;
ll n;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        snow.pb(x);
    }
    vector<ll> actm(n);
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        temp.pb(x);
    }
    actm[0] = temp[0];
    for(ll i = 1; i < n; i++) actm[i] = temp[i] + actm[i-1];
    vector<ll> death(n+1, 0);
    vector<ll> ans(n, 0);
    ll d = lower_bound(actm.begin(), actm.end(), snow[0]) - actm.begin();
    if(d == 0)
        ans[d] += snow[0];
    else if(d < n)
        ans[d] += snow[0] - actm[d-1];
    death[d]++;
    for(ll i = 1; i < n; i++) {
        if (snow[i] == 0) {
            death[i]++;
            continue;
        }
        ll d = lower_bound(actm.begin(), actm.end(), snow[i] + actm[i-1]) - actm.begin();
        if(d == n) continue;
        ans[d] += snow[i] + actm[i-1] - actm[d-1];
        death[d]++;
    }
    for(ll i = 1; i < n; i++) death[i] += death[i-1];
    for(ll i = 0; i < n; i++) ans[i] += (i + 1 - death[i]) * temp[i];
    for(ll i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}
