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
#define OO LLONG_MAX/100
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

ll vpd[11][101];
ll vpd2[11][101];
ll n;
ll num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll pd(ll k, ll m){
    if(k==10) return OO;
    if(m < 0) return OO;
    if(m==0) return 0;
    if(vpd[k][m]!=-1) return vpd[k][m];

    if(m-num[k]!=6)
        vpd[k][m] = min(k + 10*pd(0, m-num[k]), pd(k+1, m));
    else
        vpd[k][m] = min(k + 10*pd(1, m-num[k]), pd(k+1, m));

    //cout << "K: " << k << " M: " << m << " ANS: " << vpd[k][m] << endl;
    return vpd[k][m];
}
ll pd2(ll k, ll m){
    if(k==10) return -OO;
    if(m < 0) return -OO;
    if(m==0) return 0;
    if(vpd2[k][m]!=-1) return vpd2[k][m];

    vpd2[k][m] = max(k + 10*pd2(1, m-num[k]), pd2(k+1, m));
    
    //cout << "K: " << k << " M: " << m << " ANS: " << vpd[k][m] << endl;
    return vpd2[k][m];
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ms(vpd, -1);
        ms(vpd2, -1);
        ll ans, ans2;

        if(n!=6)ans = pd(0, n);
        else ans = pd(1, n);

        ans2 = pd2(0, n);

        cout << ans << " " << ans2 << "\n";
    }
}
