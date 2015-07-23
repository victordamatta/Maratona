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
#define vit vector<ll>::iterator
#define sit set<ll>::iterator
#define MOD 1000000007
#define OO ll_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

ll vpd[507][10007];
ll wes[501], vs[501];
ll t, n;

ll pd(ll k, ll w){
    if(w==0) return 0;
    if(w < 0) return INT_MAX;
    if(k == n) return INT_MAX;
    if(vpd[k][w] != -1) return vpd[k][w];

    vpd[k][w] = min(vs[k] + pd(0, w - wes[k]), pd(k+1, w));

    return vpd[k][w];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        ll e, f;
        ms(vpd, -1);
        cin >> e >> f;
        cin >> n;
        f(n, i){
            cin >> vs[i] >> wes[i];
        }
        ll ans = pd(0, f-e); 
        if(ans == INT_MAX) 
            cout << "This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is " << ans << ".\n";
    }
}
