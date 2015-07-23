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
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int divs[1000007];
int mat[1000007][15];

int main(){
    std::ios::sync_with_stdio(false);
    int t, n, a, b;
    ms(divs, 0);
    ms(mat, 0);
    for(ll i=2; i<=1000000; i++){
        if(divs[i]>0) continue;
        for(ll j=i; j<=1000000; j+=i){
            divs[j]++;
        }
    }
    for(int i=2; i<=1000000; i++){
        mat[i][divs[i]] = 1;
    }
    for(int i = 0; i<11; i++){
        for(int j=2; j<=1000000; j++){
            mat[j][i] += mat[j-1][i];
        }
    }
    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        if(n==0) cout << "1\n";
        else{
            a = max(a-1, 1);
            int ans = mat[b][n] - mat[a][n];
            cout << ans << "\n";
        }
    }
}
