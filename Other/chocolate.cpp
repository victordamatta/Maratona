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
int vpd[100007][1007];

int pd(int n, int k){
    if(n==0) return 0;
    if(vpd[n][k]!=-1) return vpd[n][k];

    int aux=1, l = min(n, m);
    for(int i=1; i<=l; i++){
        if(i!=k)
            aux *= pd(n-i, i);
    }
    if(aux) vpd[n][k] = 0;
    else vpd[n][k] = 1;

    return vpd[n][k];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    ms(vpd, -1);
    int ans = pd(n, 0);
    if(ans)
        cout << "Paula" << endl;
    else
        cout << "Carlos" << endl;
}
