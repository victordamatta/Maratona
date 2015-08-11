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

ll coins[] = {1, 5, 10, 25, 50};
ll n;
ll vpd[7][30007];

ll pd(ll k, ll m){
    if(m==0) return 1;
    if(m < 0) return 0;
    if(k > 4) return 0;
    if(vpd[k][m]!=-1) return vpd[k][m];

    vpd[k][m] = pd(k, m-coins[k]) + pd(k+1, m);

    return vpd[k][m];
}

int main(){
    ms(vpd, -1);
    while(scanf("%lld", &n)!=EOF){
        ll ans = pd(0, n);
        if(ans == 1) printf("There is only 1 way to produce %lld cents change.\n", n);
        else printf("There are %lld ways to produce %lld cents change.\n", ans, n);
    }
}
