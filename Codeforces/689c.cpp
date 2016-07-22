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
//REMEMBER TO INITIALZE THINGS
ll m;
ll count (ll x) {
    ll ans = 0;
    for (ll i = 2; i*i*i <= x; i++) {
        ans += (x / (i*i*i));
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> m;
    ll ini = 1;
    ll fim = 8 * m;
    while (ini < fim) {
        ll mid = (ini + fim)/2;
        //cout << mid << endl;
        if (count (mid) >= m) fim = mid;
        else ini = mid + 1;
    }
    if (count (fim) == m) cout << fim << endl;
    else cout << -1 << endl;
}
