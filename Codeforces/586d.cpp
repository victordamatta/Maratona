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

int t, n, k;
int vpd[5][200];
char m[5][200];

int pd(int i, int j){
    if(j >= n) return 1;
    if(i < 0 || i > 2) return 0;
    if(m[i][j] != '.') return 0;
    if(vpd[i][j] != -1) return vpd[i][j];

    if(j < n-1 && m[i][j+1] != '.') return 0;
    j++;
    if(j < n-1 && m[i][j+1] != '.') return 0;
    j++;
    if(j < n-1 && (m[i][j+1] != '.')) return 0;
    j++;
    vpd[i][j] = pd(i + 1, j) || pd(i, j) || pd(i - 1, j);
    return vpd[i][j];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        int ans = 0;
        ms(vpd, -1);
        cin >> n >> k;
        f(n, i) cin >> m[0][i];
        f(n, i) cin >> m[1][i];
        f(n, i) cin >> m[2][i];
        if(m[0][0] == 's'){
            if(m[0][1]=='.')
                ans = pd(0, 1) || pd(1, 1);   
        }
        else if(m[1][0] == 's'){
            if(m[1][1]=='.')
                ans = pd(0, 1) || pd(1, 1) || pd(2, 1);   
        }
        else if(m[2][0] == 's'){
            if(m[2][1]=='.')
                ans = pd(1, 1) || pd(2, 1);   
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
