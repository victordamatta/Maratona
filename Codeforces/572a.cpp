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

int main(){
    std::ios::sync_with_stdio(false);
    ll na, nb, k, m, a[100005], b[100005];
    cin >> na >> nb >> k >> m;
    f(na, i){
        cin >> a[i];
    }
    f(nb, i){
        cin >> b[i];
    }
    if(b[nb-m] <= a[k-1])
        cout << "NO\n";
    else
        cout << "YES\n";
}
