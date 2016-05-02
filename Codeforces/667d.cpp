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
vi graph[3007];
int dist[3007][3007];
int n, m;
int bef[3007][7];
int aft[3007][7];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    f (m, i) {
        int a, b;
        cin >> a >> b;
        graph[a].pb (b);
    }

    for (int i = 1; i <= n; i++) {
        queue<int> q;
        q.push (i);
        while (!q.empty ()) {
            int v = q.front ();
            q.pop ();
            for (int u: graph[v]) {
                if(v == u) continue;
                if (dist[i][u] == 0) {
                    dist[i][u] = dist[i][v] + 1;
                    q.push (u);
                }
            }
        }
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            bef[i][j] = i, aft[i][j] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!dist[i][j]) continue;
            int f = aft[i][0], s = aft[i][1], t = aft[i][2];
            if (dist[i][j] >= dist[i][f]) {
                aft[i][2] = s;
                aft[i][1] = f;
                aft[i][0] = j;
            }
            else if (dist[i][j] >= dist[i][s]) {
                aft[i][2] = s;
                aft[i][1] = j;
            }
            else if (dist[i][j] >= dist[i][t]) {
                aft[i][2] = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!dist[j][i]) continue;
            int f = bef[i][0], s = bef[i][1], t = bef[i][2];
            if (dist[j][i] >= dist[f][i]) {
                bef[i][2] = s;
                bef[i][1] = f;
                bef[i][0] = j;
            }
            else if (dist[j][i] >= dist[s][i]) {
                bef[i][2] = s;
                bef[i][1] = j;
            }
            else if (dist[j][i] >= dist[t][i]) {
                bef[i][2] = j;
            }
        }
    }

    int ans = 0;
    int a, b, c, d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == 0) continue;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int aa = bef[i][k], ab = i, ac = j, ad = aft[j][l];
                    if (aa != ab && aa != ac && aa != ad && ab != ac && ab != ad && ac != ad) {
                        if (ans < dist[aa][ab] + dist[ab][ac] + dist[ac][ad]) {
                            ans = dist[aa][ab] + dist[ab][ac] + dist[ac][ad];
                            a = aa, b = ab, c = ac, d = ad;
                        }
                    }
                }
            }
        }
    }
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
}
