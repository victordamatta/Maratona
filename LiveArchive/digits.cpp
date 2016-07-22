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
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THING
ll sum (ll a, ll b) {
    if (a < 0 || b < 0) return -1;
    ll ans = 0;
    while (a > 0) {
        ans += a % 10;
        a /= 10;
    }
    while (b > 0) {
        ans += b % 10;
        b /= 10;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll ans = 0, aux = 0;
    ll fs, sc;
    while (aux <= n) {
        int s = sum (aux, n - aux);
        if (s > ans) {
            ans = s;
            fs = aux;
            sc = n - aux;
        }
        aux *= 10;
        aux += 9;
    }
    cout << ans << endl;
    cout << fs << " " << sc << endl;
}
