#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const ll OO = 5e18;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
ll n, m, k;
ll x, s;
ll a[200007], b[200007], c[200007], d[200007];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> x >> s;
    f (m, i) cin >> a[i];
    f (m, i) cin >> b[i];
    f (k, i) cin >> c[i];
    f (k, i) cin >> d[i];

    ll ans = n * x, tans = OO;
    for (ll i = m - 1; i >= 0; i--) {
        ll t = s - b[i];
        if (t < 0) continue;

        ll lo = 0, hi = k-1;
        ll mid = -1;
        while (lo < hi) {
            mid = (hi + lo) / 2;
            if (mid == lo) break;
            if (d[mid] <= t) lo = mid;
            else hi = mid - 1;
        }
        if (d[hi] <= t) {
            tans = (n - c[hi]) * a[i];
            /* cout << "hi is good\n"; */
        }
        else if (d[lo] <= t) {
            tans = (n - c[lo]) * a[i];
            /* cout << "lo is good\n"; */
        }
        else {
            tans = n * a[i];
            /* cout << "nill is good\n"; */
        }
        /* cout << tans << endl; */
        /* cout << lo << " " << hi << endl; */
        if (tans < ans) ans = tans;
    }
    for (ll i = 0; i < k; i++) {
        if (d[i] <= s) tans = (n - c[i]) * x;
        if (tans < ans) ans = tans;
    }

    cout << ans << endl;
}
