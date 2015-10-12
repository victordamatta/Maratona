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

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    int v[5000], d[5000], p[5000];
    cin >> n;
    f(n, i){
        cin >> v[i] >> d[i] >> p[i];
    }
    int i = 0, ans = 0;
    while (i < n) {
        if(p[i] < 0) {
            i++;
            continue;
        }
        ans++;
        int sc = v[i], ts = 0;
        for(int j = i+1; j < n; j++){
            if(sc==0 && ts==0) break;
            p[j] -= sc + ts;
            if(p[j] < 0) ts += d[j];
            sc = max(sc-1, 0);
        } 
        i++;
    }
    cout << ans << "\n";
    f(n, i){
        if(p[i] >= 0) cout << i+1 << " ";
    }
    cout << "\n";
}
