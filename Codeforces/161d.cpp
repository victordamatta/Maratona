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
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 0x3f3f3f;
//REMEMBER TO DECLARE GLOBAL VARIABLES
vi graph[50007];
int p[50007];
int n, k;
ll vpdd[50007][507];
int vpdu[50007][507];

ll dfs(int v, int pv){
    f(graph[v].size(), i){
        if(graph[v][i] == pv) continue;
        p[graph[v][i]] = v;
        dfs(graph[v][i], v);
    }
}

int pdd(int v, int l){
    if(l == 0) return 1;
    if(l < 0) return 0;
    if(vpdd[v][l] != -1) return vpdd[v][l];

    ll ans = 0;
    f(graph[v].size(), i){
        if(graph[v][i] == p[v]) continue;
        ans += pdd(graph[v][i], l-1);
    }

    vpdd[v][l] = ans;
    return ans;
}

int pdu(int v, int l){
    if(l == 0) return 1;
    if(l < 0) return 0;
    if(vpdu[v][l] != -1) return vpdu[v][l];

    ll ans = 0;
    ans += pdd(v, l);
    if(p[v] != v){
        ans += pdu(p[v], l-1);
        ans -= pdd(v, l-2);
    }

    vpdu[v][l] = ans;
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    ms(vpdd, -1);
    ms(vpdu, -1);
    f(n-1, i){
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    p[1] = 1;
    dfs(1, 1);
    ll ans = 0;
    f(n, i){
        ans += pdu(i+1, k);
    }
    ans /= 2;
    cout << ans << "\n";
}
