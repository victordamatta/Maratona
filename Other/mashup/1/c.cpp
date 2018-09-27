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
int n, s;
ll paths[40007];
vi graph[40007];
ll dist[40007];

ll dista (int v) {
    if (dist[v] != -1) return dist[v];
    if (v == n) return 1;

    dist[v] = 0;
    for (int u : graph[v]) {
        dist[v] = max (dist[v], dista(u) + paths[v]);
    }
    return dist[v];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> s;
    f (s, i) {
        int a, b;
        cin >> a >> b;
        graph[a].pb (b);
    }
    paths[n] = 1;
    for (int i = n; i > 0; i--) {
        for (int j : graph[i]) {
            paths[i] += paths[j];
        }
    }

    ms (dist, -1);
    cout << dista(1) << endl;
}
