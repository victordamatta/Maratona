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

int h, w, mat[107][107];
int vpd[107][107];

int pd(int i, int j){
    if(i==h) return 0;
    if(j<0) return -OO;
    if(j==w) return -OO;
    if(vpd[i][j]!=-1) return vpd[i][j];

    vpd[i][j] = mat[i][j] + max(pd(i+1, j-1), max(pd(i+1, j), pd(i+1, j+1)));

    return vpd[i][j];
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> h >> w;
        f(h, i){
            f(w, j){
                cin >> mat[i][j];
            }
        }
        ms(vpd, -1);
        int ans=0, aux;
        for(int i=0; i<w; i++){
            aux = pd(0, i);
            if(aux > ans) ans = aux;
        }
        cout << ans << "\n";
    }
}
