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
#define all(x) x.begin(), x.end()
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
const ll OO = 0x3f3f3f;
//REMEMBER LONG LONG ll
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    map<ll, ll> mx;
    map<ll, ll> my;
    vpi v;
    cin >> n;
    ll ans = 0ll;
    f (n, i) {
        ll a, b;
        cin >> a >> b;
        v.pb (mp (a, b));
        if (mx.find(a) != mx.end()) {
            ans += mx[a];
            mx[a] += 1;
        }
        else {
            mx[a] = 1;
        }
        if (my.find(b) != my.end()) {
            ans += my[b];
            my[b] += 1;
        }
        else {
            my[b] = 1;
        }
    }
    sort (all(v));
    pi past = mp (1000000001, 1000000001);
    ll sam = 1;
    f (v.size (), i) {
        if (v[i] == past) sam++;
        else {
            ans -= (sam*(sam-1))/2;
            sam = 1;
        }
        past = v[i];
    }
    ans -= (sam*(sam-1))/2;
    cout << ans << "\n";
}
