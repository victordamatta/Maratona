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
vi graph[200007];
int vis[200007];
map<int, int> comp;
int cycles, kids;

void dfs(int node, int par){
    kids++;
    vis[node] = 1;
    int aux = 0;
    f(graph[node].size(), i){
        if(graph[node][i] != par){
            if(vis[graph[node][i]])
                cycles = 1;
            else
                dfs(graph[node][i], node);
        }
    }
}

int x, k, w;
int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> k >> w, k != 0){
        cycles = 0;
        kids = 0;
        ms(vis, 0);
        x = 0;
        int ok = 1;
        int every = 0;
        f(w, i){
            int a, b;
            cin >> a >> b;
            if(comp.find(a) == comp.end()) comp[a] = x++;
            if(comp.find(b) == comp.end()) comp[b] = x++;
            int g, h;
            g = comp[a];
            h = comp[b];
            graph[g].pb(h);
            graph[h].pb(g);

            sort(all(graph[g]));
            vi::iterator it = unique(all(graph[g]));
            graph[g].resize(distance(graph[g].begin(), it));

            sort(all(graph[h]));
            it = unique(all(graph[h]));
            graph[h].resize(distance(graph[h].begin(), it));

            if(graph[h].size() > 2){
                ok = 0;
            }
            if(graph[g].size() > 2){
                ok = 0;
            }
        }
        if(ok){
            kids = 0;
            f(x, i){
                dfs(i, -1);
                if(cycles) break;
            }
        }
        else{
            cout << "N\n";
        }
        if(kids == k) every = 1;
        f(x, i){
            graph[i].clear();
        }
        if(ok && cycles && every) cout << "Y\n";
        else if (ok && cycles) cout << "N\n";
        else if(ok) cout << "Y\n";
        comp.clear();
    }
}
