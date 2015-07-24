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
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, m; 
int vpd[100007][1007];

int pd(int s, int p){
    if(s==0) return 0;
    if(s<=m && s!=p) return 1;
    if(vpd[s][p]!=-1) return vpd[s][p];

    int mi = min(s, m), ans = 1;
    for(int i=1; i<=mi; i++){
        if(i!=p){
            ans *= pd(s-i, i);
        }
    }
    if(ans == 0) vpd[s][p] = 1;
    else vpd[s][p] = 0;

    return vpd[s][p];
}

int main(){
    std::ios::sync_with_stdio(false);
    ms(vpd, -1);
    cin >> n >> m;
    int ans = pd(n, 0);
    cout << ans << endl;
}
