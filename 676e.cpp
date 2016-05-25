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
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll> > vpi;
typedef set<ll> si;
typedef set<ll>::iterator sit;
const ll MOD = 1000000007;
const ll MOD2 = 1000000207;
const ll MOD3 = 1000001699;
const ll OO = 1000000000;
//REMEMBER LONG LONG ll
//REMEMBER TO INITIALZE THINGS
ll Pow (ll k, ll e, ll m) {
    if (e == 0) return 1;
    if (e % 2 == 0) {
        return Pow ((k * k) % m, e/2, m) % m;
    }
    else {
        return (k * Pow ((k * k) % m, (e-1)/2, m)) % m;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll ok = 0;
    ll cur1 = 0;
    ll cur2 = 0;
    ll cur3 = 0;
    f (n+1, i) {
        string c;
        cin >> c;
        if (c.compare ("?") == 0) {
            if (n % 2 == 1) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
            return 0;
        }
        ll num = stoi (c);
        ll xp = num * Pow (k, i, MOD);
        cur1 = (cur1 + xp) % MOD;
        xp = num * Pow (k, i, MOD2);
        cur2 = (cur2 + xp) % MOD2;
        xp = num * Pow (k, i, MOD3);
        cur3 = (cur3 + xp) % MOD3;
    }
    if (cur1 == 0 && cur2 == 0 && cur3 == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}
