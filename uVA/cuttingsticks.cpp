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

int n, s;
int cuts[60];
int vpd[1007][1007];

int pd(int l, int r, int a, int b){
    if(a>b) return 0;
    if(r==l) return 0;
    if(vpd[l][r]!=-1) return vpd[l][r];

    int ans = INT_MAX;
    for(int i=a; i<=b; i++){
        ans = min(ans, r-l + pd(l, cuts[i], a, i-1) + pd(cuts[i], r, i+1, b));
    }

    vpd[l][r] = ans;
    return vpd[l][r];
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> s, s!=0){
        cin >> n;
        f(n, i){
            cin >> cuts[i];
        }
        ms(vpd, -1);
        cout << "The minimum cutting is " << pd(0, s, 0, n-1) << ".\n";
    }
}
