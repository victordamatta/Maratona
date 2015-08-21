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
int in[1007];
int vpd[1007][1007];

int pd(int l, int r, int size){
    if(size==0) return 0;
    if(vpd[l][r]!=-2000000) return vpd[l][r];

    int ans1, ans2;
    ans1 = in[l];
    if(size==2 || in[r]>in[l+1]){
        ans1 -= in[r];
        ans1 += pd(l+1, r-1, size-2);
    }
    else{
        ans1 -= in[l+1];
        ans1 += pd(l+2, r, size-2);
    }
    ans2 = in[r];
    if(size==2 || in[l]>=in[r-1]){
        ans2 -= in[l];
        ans2 += pd(l+1, r-1, size-2);
    }
    else{
        ans2 -= in[r-1];
        ans2 += pd(l, r-2, size-2);
    }

    vpd[l][r] = max(ans1, ans2);

    //cout << l << " " << r << " " << vpd[l][r] << "\n";
    return vpd[l][r];
}

int main(){
    std::ios::sync_with_stdio(false);
    int cont = 0;
    while(cin >> n, n!=0){
        cont++;
        for(int i=0; i<1005; i++){
            for(int j=0; j<1005; j++){
                vpd[i][j] = -2000000;
            }
        }
        f(n, i){
            cin >> in[i];
        }
        int ans = pd(0, n-1, n);
        cout << "In game " << cont << ", the greedy strategy might lose by as many as " << ans << " points.\n";
    }
}
