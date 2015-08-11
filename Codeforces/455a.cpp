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
ll n, m;
ll freq[100007];
ll vpd[100007];

ll pd(ll k){
    if(k>m) return 0;
    if(vpd[k]!=-1) return vpd[k];

    vpd[k] = max(freq[k]*k + pd(k+2), pd(k+1));

    return vpd[k];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    ms(freq, 0);
    ms(vpd, -1);
    ll aux;
    m = 0;
    f(n, i){
        cin >> aux;
        freq[aux]++;
        if(aux > m) m = aux;
    }
    ll ans = pd(0);
    cout << ans << "\n";
}
