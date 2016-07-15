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
int n, m;
int u, v;
vi graph[207];
pi eds[2007];
int dist[207];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    f (m, i) {
        int a, b;
        cin >> a >> b;
        graph[a].pb (b);
        eds[i].fst = a;
        eds[i].scd = b;
    }
    cin >> u >> v;

    f (m, i) {
        queue<int> q;
        q.push (u);
        ms (dist, -1);
        while (!q.empty ()) {
            int v = q.front ();
            q.pop ();
            for (int u : graph[v]) {
                if (v == eds[i].fst && u == eds[i].scd) continue;
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    q.push (u);
                }
            }
        }
        if (dist[v] == -1) {
            cout << "1\n";
            return 0;
        }
    }
    cout << "0\n";
}
