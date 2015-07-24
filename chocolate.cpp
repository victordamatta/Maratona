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

int n, m;
int vpd[1000007];

int pd(int n){
    if(n==0) return 0;
    if(n<=m) return n;
    if(vpd[n]!=-1) return vpd[n];

    int aux, wins=0, k=0;
    for(int i=1; i<=m; i++){
        aux = pd(n-i);
        if(aux == 0 || aux==i) k = i;
    }
    if(wins) vpd[n] = k;
    else vpd[n] = 0;

    return vpd[n];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int ans = pd(n);
    cout << ans << endl;
}
