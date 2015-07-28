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

int n;
int trs[3000];
int vpd[2007][2007];

int pd(int a, int l){
    if(a>n) return 0;
    if(vpd[a][l]!=-1) return vpd[a][l];

    vpd[a][l] = max(trs[l]*a + pd(a+1, l+1), trs[n-(a-l)]*a + pd(a+1, l));

    return vpd[a][l];
}

int main(){
    std::ios::sync_with_stdio(false);
    ms(vpd, -1);
    cin >> n;
    f(n, i){
        cin >> trs[i];
    }
    int ans = pd(1, 0);
    cout << ans << "\n";
}
