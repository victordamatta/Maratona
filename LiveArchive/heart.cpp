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
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
vi graph[1007];
int n, k;
int troops[1007];
int def[1007];
int fallen[1007];
int visited[1007];
int sum, ans;

void dfs (int v) {
    if (visited[v] || fallen[v]) return;
    visited[v] = 1;
    sum += troops[v];
    ans++;
    for (int u:graph[v]) {
        dfs (u);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    while (cin >> n >> k, n != 0) {
        f (1007, i) graph[i].clear (), def[i] = 0, troops[i] = 0, fallen[i] = 0, visited[i] = 0;

        f (n, i) {
            int troop, adj;
            cin >> troop;
            def[i] += troop;
            troops[i] = troop;
            cin >> adj;
            f (adj, j) {
                int c;
                cin >> c;
                graph[i].pb (c);
                def[c] += troop;
            }
        }
        bool none = true;
        while (none) {
            none = false;
            f (n, v) {
                if (!fallen[v] && def[v] < k) {
                    none = true;
                    fallen[v] = 1;
                    for (int u:graph[v]) {
                        def[u] -= troops[v];
                    }
                }
            }
        }
        sum = ans = 0;
        f (n, i) {
            if (!fallen[i]) {
                sum += troops[i];
                ans++;
            }
        }
        cout << ans << " " << sum << "\n";
    }
}
