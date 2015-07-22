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

int mm, m; 
int vpd[1000001][2];
int gt;

int pd(int n, int p, int t){
    if(n==0 && t==gt) return 0;
    if(n==0) return 1;
    if(n<=m) return pd(0, n, (t+1)%2);
    if(vpd[n][t]>=0) return vpd[n][t];

    int ans = 1;
    for(int i=1; i<=m; i++){
        if(i!=p){
            ans *= pd(n-i, i, (t+1)%2);
        }
    }

    vpd[n][t] = abs(vpd[n][t]*ans);
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    ms(vpd, -1);
    cin >> mm >> m;
    int ans, p, aux;
    if(m%2==0){
        if(mm%(m+1)==0) cout << "Carlos\n";
        else cout << "Paula\n";
    }
    else{
        gt = 0;
        while(mm>0){
            aux = mm%(m+1);
            if(p!=mm && mm<=m){
                mm = 0;
                gt = (gt+1)%2;
            }
            else if(p!=aux){
                mm = 0;
                gt = (gt+1)%2;
            }
            else{
                if(p!=(m+1)/2 && aux==(m+1)/2){
                    mm -= (m+1)/2;
                    p = (m+1)/2;
                    gt = (gt+1)%2;
                }
                else{
                    mm = 0;
                }
            }
        }
        if(gt==1) cout << "Paula\n";
        else cout << "Carlos\n";
    }
}
