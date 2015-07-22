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
int mat[1000007][20];

int main(){
    std::ios::sync_with_stdio(false);
    int t, n, a, b;
    ms(divs, 0);
    ms(mat, 0);
    for(int i=2; i<=1000; i++){
        if(divs[i]>0) continue;
        for(int j=i*i; j<=1000000; j+=i){
            divs[j]++;
        }
    }
    for(int i=2; i<=1000000; i++){
        mat[i][divs[i]] = 1;
    }
    for(int i = 0; i<20; i++){
        for(int j=3; j<=1000000; j++){
            mat[j][i] += mat[j-1][i];
        }
    }
    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        int ans = mat[n][b] - mat[n][a-1];
        cout << ans << "\n";
    }
}
