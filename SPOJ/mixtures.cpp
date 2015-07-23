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

int n, vet[107], mix[107][107];
int vpd[107][107];

int pd(int l, int r){
    if(l==r){
        mix[l][r] = vet[l];
        return 0;
    }
    if(vpd[l][r]!=-1) return vpd[l][r];

    int aux, ans=INT_MAX;
    for(int k=l; k<r; k++){
        aux = pd(l, k) + pd(k+1, r) + mix[l][k]*mix[k+1][r];
        if(aux < ans){
            ans = aux;
            mix[l][r] = (mix[l][k] + mix[k+1][r])%100;
        }
    }

    vpd[l][r] = ans;
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin.peek()!=EOF){
        cin >> n;
        ms(vpd, -1);
        f(n, i){
            cin >> vet[i];
        }
        int ans = pd(0, n-1);
        cout << ans << "\n";
        cin.get();
    }
}
