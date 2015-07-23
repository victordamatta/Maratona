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

int n, mat[15][2000];
int vpd[15][2000];

int pd(int i, int j){
    if(j==n && i==0) return 0;
    if(i<0 || i>=10) return OO;
    if(j==n) return OO;
    if(vpd[i][j]!=-1) return vpd[i][j];

    vpd[i][j] = min(60+pd(i-1, j+1), min(30+pd(i, j+1), 20+pd(i+1, j+1))) - mat[i][j];

    return vpd[i][j];
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ms(vpd, -1);
        cin >> n;
        n/=100;
        f(10, i){
            f(n, j){
                cin >> mat[9-i][j];
            }
        }
        int ans = pd(0, 0);
        cout << ans << "\n\n";
    }
}
