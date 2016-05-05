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
#define MAX 1000007ll
ll fa[MAX], fb[MAX];
ll crivo[MAX];

int main(){
    std::ios::sync_with_stdio(false);
    ll a, b;
    ll t = 1;
    f(MAX, i) crivo[i] = i;
    for (ll i = 2; i < MAX; i++) {
        if (crivo[i] != i) continue;
        for (ll j = i*i; j < MAX; j += i) {
            crivo[j] = i;
        }
    }
    while (cin >> a >> b, a != 0) {
        if (a == 1 && b == 1) {
            cout << t << ". " << 1 << ":" << 0 << endl;
            t++;
            continue;
        }
        ms (fa, 0);
        ms (fb, 0);
        set<ll> s;
        while (a > 1) {
            s.insert (crivo[a]);
            fa[crivo[a]]++;
            a /= crivo[a];
        }
        while (b > 1) {
            s.insert (crivo[b]);
            fb[crivo[b]]++;
            b /= crivo[b];
        }
        ll dif = 0;
        for (ll i = 0; i < 1000005; i++) {
            dif += abs (fa[i] - fb[i]);
            /* if (fa[i] != 0 || fb[i] != 0) { */
            /*     cout << i << endl; */
            /* } */
        }
        cout << t << ". " << s.size () << ":" << dif << endl;
        t++;
    }
}
