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

int expr[100], n, k;
int vpd[100][100];

int pd(int p, int s){
    if(p==2*n && s==0) return 1;
    if(s<0) return 0;
    if(p==2*n) return 0;
    if(vpd[p][s]!=-1) return vpd[p][s];

    int ans;
    if(expr[p])
        ans = pd(p+1, s-1) + pd(p+1, s+1);
    else
        ans = pd(p+1, s+1);

    vpd[p][s] = ans;
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ms(vpd, -1);
        ms(expr, 1);
        cin >> n >> k;
        int aux;
        f(k, i){
            cin >> aux;
            expr[aux-1] = 0;
        }
        int ans = pd(0, 0);
        cout << ans << "\n";
    }
}
