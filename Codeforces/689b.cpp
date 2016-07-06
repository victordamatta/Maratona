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
int dist[200007];
vi graph[200007];

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    f (n, i) dist[i+1] = OO;
    f (n, i) {
        int sc;
        cin >> sc;
        graph[i+1].pb (sc);
    }
    graph[1].pb (2);
    for (int i = 2; i < n; i++) {
        graph[i].pb (i+1);
        graph[i].pb (i-1);
    }
    graph[n].pb (n-1);
    queue<int> q;
    dist[1] = 0;
    q.push (1);
    while (!q.empty ()) {
        int v = q.front();
        q.pop ();

        for (int u : graph[v]) {
            if (dist[u] == OO) {
                dist[u] = dist[v] + 1;
                q.push (u);
            }
        }
    }
    dist[1] = 0;
    f (n, i) cout << dist[i+1] << " ";
    cout << endl;
}
