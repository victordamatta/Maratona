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
vi graph[200007];
int color[200007];
vi graph2[200007];
int color2[200007];
int n;
int visited[200007];
int comp[200007];
int co;
int ans0, ans1;

void dfs (int v, int c) {
    if (visited[v]) return;
    if (color2[v] == c) {
        if (graph2[v].size () > 1) {
            if (c == 0) ans0++;
            else ans1++;
        }
    }
    visited[v] = 1;
    for (int u : graph2[v]) dfs (u, c);
}

void mark (int v) {
    if (visited[v]) return;
    visited[v] = 1;
    for (int u : graph[v]) {
        mark (u);
        comp[u] = co;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    co = 1;
    f (n, i) cin >> color[i];
    f (n-1, i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].pb (b);
        graph[b].pb (a);
    }
    f (n, i) {
        if (comp[i] != 0) continue;
        co++;
        comp[i] = co;
        mark (i);
    }
    f (n, i) {
        for (int j : graph[i]) {
            if (comp[i] != comp[j]) {
                graph2[comp[i]].pb (comp[j]);
                graph2[comp[j]].pb (comp[i]);
            }
        }
    }
    f (n, i) {
        color2[comp[i]] = color[i];
    }

    ans0 = 0, ans1 = 0;
    f (n, i) visited[i] = 0;
    f (n, i) {
        if (color2[comp[i]] == 0|| visited[comp[i]] == 1) continue;
        ans0++;
        dfs (comp[i], 0);
    }

    f (n, i) visited[i] = 0;
    f (n, i) {
        if (color2[comp[i]] == 1|| visited[comp[i]] == 1) continue;
        ans1++;
        dfs (comp[i], 1);
    }
    cout << min (ans0, ans1) << endl;
}
