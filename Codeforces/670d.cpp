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
const ll OO = 1000000000;
//REMEMBER LONG LONG ll
//REMEMBER TO INITIALZE THINGS
ll n, k;
vi needs;
vi has;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    f (n, i) {
        ll aux;
        cin >> aux;
        needs.pb (aux);
    }
    f (n, i) {
        ll aux;
        cin >> aux;
        has.pb (aux);
    }
    ll ini = 0, fim = 1000 + k;
    ll ans;
    while (ini < fim) {
        ll mid = (ini + fim) / 2;
        if (mid == ini) break;
        ll tk = k;
        bool ok = true;
        f (n, i) {
            ll aux = has[i] - mid*needs[i];
            if (aux < 0) tk += aux;
            if (tk < 0) ok = false;
        }
        if (ok) {
            ini = mid;
        }
        else {
            fim = mid - 1;
        }
    }
    ll ok = true;
    f (n, i) {
        ll aux = has[i] - fim*needs[i];
        if (aux < 0) k += aux;
        if (k < 0) ok = false;
    }
    if (ok) cout << fim << endl;
    else cout << ini << endl;
}
