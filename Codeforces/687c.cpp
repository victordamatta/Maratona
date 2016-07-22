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
vi graph[100007];
int color[100007];
int flip (int x) {
    if (x == 1) return -1;
    return 1;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    f (m, i) {
        cin >> a >> b;
        graph[a].pb (b);
        graph[b].pb (a);
    }

    int ok = 1;
    for (int i = 1; i <= n; i++) {
        if (color[i] != 0) continue;
        color[i] = 1;
        queue<int> q;
        q.push (i);
        while (!q.empty ()) {
            int v = q.front ();
            q.pop ();
            for (int u: graph[v]) {
                if (color[u] == 0) {
                    color[u] = flip (color[v]);
                    q.push (u);
                }
                else {
                    if (color[u] != flip (color[v])) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok == 0) break;
        }
        if (ok == 0) break;
    }
    if (ok) {
        vi black;
        vi red;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) black.pb (i);
            else if (color[i] == -1) red.pb (i);
        }
        cout << black.size () << endl;
        for (int v: black) cout << v << " ";
        cout << endl;
        cout << red.size () << endl;
        for (int v: red) cout << v << " ";
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
}
