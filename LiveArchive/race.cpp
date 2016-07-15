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
int grid[30][30];
int dist[30][30];
int n, m;
int hx[] = {0, 1, 0, -1};
int hy[] = {1, 0, -1, 0};

int pd (pi p, int dir) {
    int ans = -1;
    while (p.fst < n && p.scd < m && p.fst >= 0 && p.scd >= 0 && !grid[p.fst][p.scd]) {
        p.fst += hx[dir];
        p.scd += hy[dir];
        ans++;
    }
    /* if (grid[p.fst][p.scd]) ans--; */
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    pi start;
    pi end;
    cin >> n >> m;
    f (n, i) {
        f (m, j) {
            char aux;
            cin >> aux;
            if (aux == 'S') {
                grid[i][j] = 0;
                start.fst = i;
                start.scd = j;
            }
            else if (aux == 'T') {
                grid[i][j] = 0;
                end.fst = i;
                end.scd = j;
            }
            else if (aux == '.') grid[i][j] = 0;
            else grid[i][j] = 1;

            dist[i][j] = OO;
        }
    }

    queue<pi> q;
    q.push (start);
    dist[start.fst][start.scd] = 0;
    while (!q.empty ()) {
        pi cur = q.front ();
        q.pop ();
        f (4, i) {
            int d = pd (cur, i) - pd (cur, i)/2;
            if (dist[cur.fst+d*hx[i]][cur.scd+d*hy[i]] == OO) {
                dist[cur.fst+d*hx[i]][cur.scd+d*hy[i]] = dist[cur.fst][cur.scd] + 1;
                q.push (mp (cur.fst+d*hx[i], cur.scd+d*hy[i]));
            }
        }
    }
    /* f (n, i) { */
    /*     f (m, j) { */
    /*         printf ("%10d ", dist[i][j]); */
    /*     } */
    /*     printf ("\n"); */
    /* } */
    if (dist[end.fst][end.scd] == OO) cout << -1 << endl;
    else cout << dist[end.fst][end.scd] << endl;
}
