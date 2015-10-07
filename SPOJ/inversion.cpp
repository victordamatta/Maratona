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
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<ll>
#define si set<ll>
#define sit set<ll>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

ll n, bit[10000007];

ll query (int k) {
    ll sum = 0;
    for (ll i = k; i>0; i -= i&-i) {
        sum += bit[i];
    }
    return sum;
}

void update (ll k) {
    for (ll i = k; i <= 10000000; i += i&-i) {
        bit[i]++;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ms (bit, 0);
        ll aux, ans = 0;
        cin >> n;
        f(n, i) {
            cin >> aux;
            update (aux);
            ans += (i + 1) - query (aux);
        }
        cout << ans << "\n";
    }
}
