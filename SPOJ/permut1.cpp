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
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define sit set<int>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int m, j;
int vpd[20][105];

int pd(int n, int k){
    if(k>j) return 0;
    if(k==j) return 1;
    if(n>m) return 0;
    if(vpd[n][k]!=-1) return vpd[n][k];

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += pd(n+1, k+i);
    }
    
    vpd[n][k] = ans;

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> m >> j;
        ms(vpd, -1);
        int ans = pd(1, 0);
        cout << ans << "\n";
    }
}
