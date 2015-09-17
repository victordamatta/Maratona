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

vector<int> g[500300];
int n, m;
int size, odd;
unsigned char cs[500300];
int countc[258], depth[500300];

void fc(int d, int v){
    if(d==0){
        countc[cs[v]]++;
        size++;
        if(countc[cs[v]]%2) odd++;
        else odd--;
        return;
    }
    for(int i=0; i < g[v].size(); i++){
        fc(d-1, g[v][i]);
    }
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int aux;
    ms(depth, 0);
    depth[1] = 1;
    for(int i=1; i<n; i++){
        cin >> aux;
        g[aux].pb(i+1);
        depth[i+1] = depth[aux]+1;
    }
    char aux2;
    for(int i=0; i<n; i++){
        cin >> aux2;
        cs[i+1] = aux2;
    }
    while(m--){
        int v, h;
        cin >> v >> h;
        odd = 0;
        size = 0;
        ms(countc, 0);
        fc(h-depth[v], v);
        if(size%2) odd--;
        if(odd==0) cout << "Yes\n";
        else cout << "No\n";
    }
}
