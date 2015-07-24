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
#define OO 1000000
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int divs[OO + 7];
int mat[15][OO + 7];

int main(){
    std::ios::sync_with_stdio(false);
    int t, n, a, b;
    ms(divs, 0);
    ms(mat, 0);
    for(ll i=2; i<=OO; i++){
        if(divs[i]>0) continue;
        for(ll j=i; j<=OO; j+=i){
            divs[j]++;
        }
    }
    for(int i=2; i<=OO; i++){
        mat[divs[i]][i] = 1;
    }
    for(int i = 0; i<11; i++){
        for(int j=2; j<=OO; j++){
            mat[i][j] += mat[i][j-1];
        }
    }
    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        if(n==0 && a==1) cout << "1\n";
        else if(n==0) cout << "0\n";
        else{
            a = max(a-1, 0);
            int ans = mat[n][b] - mat[n][a];
            cout << ans << "\n";
        }
    }
}
