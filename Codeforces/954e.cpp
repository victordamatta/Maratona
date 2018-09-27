
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
const int  N = 200004;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

pair<ll, ll> taps[N];
ll acam[N];
ll acte[N];

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.snd < b.snd;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n, target;
    cin >> n >> target;
    taps[0] = mp(0, 0);
    for(ll i = 1; i <= n; i++) {
        cin >> taps[i].fst;
    }
    for(ll i = 1; i <= n; i++) {
        cin >> taps[i].snd;
    }

    sort(taps+1, taps+n+1, cmp);

    for(ll i = 1; i <= n; i++) {
        acam[i] = taps[i].fst + acam[i-1];
        acte[i] = taps[i].snd*taps[i].fst + acte[i-1];
    }

    double hi, lo;
    lo = 0.0;
    hi = acam[n];
    int splits = 300;
    while(splits--) {
        double mid = (lo + hi) / 2.0;

        ll cit = upper_bound(acam, acam+n+1, mid) - acam;
        double coldest;
        if(cit == n+1) coldest = acte[n];
        else coldest = (acte[cit-1] + taps[cit].snd*(mid - acam[cit-1])) / mid;

        ll hit = upper_bound(acam, acam+n+1, acam[n] - mid) - acam;
        double hottest;
        if(mid < 0.5) hottest = taps[n].snd;
        else hottest = ((acte[n] - acte[hit]) + taps[hit].snd*(mid - (acam[n] - acam[hit]))) / mid;

        double eps = 1e-12;
        if(coldest < target + eps && target < hottest + eps) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(12) << (lo + hi) / 2.0 << endl;
}
