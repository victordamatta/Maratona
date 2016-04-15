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
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
struct rob {
    int x;
    int y;
    int dir;

    rob (int x, int y, int dir) : x(x), y(y), dir(dir) {};
};

int mat[207][207][7];
int bfs[207][207][7];
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ms (mat, 0);
    ms (bfs, 0);

    f(n, i) {
        f(n, j) {
            char c;
            cin >> c;
            if (c == '.') {
                mat[i][j][0] = 1;
                mat[i][j][1] = 1;
                mat[i][j][2] = 1;
                mat[i][j][3] = 1;
            }
            else {
                mat[i][j][0] = 0;
                mat[i][j][1] = 0;
                mat[i][j][2] = 0;
                mat[i][j][3] = 0;
            }
        }
    }

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    queue<rob> q;
    q.push (rob (0, 0, 0));
    while (!q.empty ()) {
        rob r = q.front ();
        q.pop ();
        if (!mat[r.x][r.y][r.dir]) continue;
        if (bfs[r.x][r.y][(r.dir+1)%4] == 0) {
            bfs[r.x][r.y][(r.dir+1)%4] = bfs[r.x][r.y][r.dir] + 1;
            q.push (rob (r.x, r.y, (r.dir+1)%4));
        }
        if (r.x+tx[r.dir] >= 0 && r.y+ty[r.dir] >=0 && r.x+tx[r.dir] < n && r.y+ty[r.dir] < n) {
            if (bfs[r.x+tx[r.dir]][r.y+ty[r.dir]][r.dir] == 0) {
                bfs[r.x+tx[r.dir]][r.y+ty[r.dir]][r.dir] = bfs[r.x][r.y][r.dir] + 1;
                q.push (rob (r.x+tx[r.dir], r.y+ty[r.dir], r.dir));
            }
        }
    }

    cout << bfs[n-1][n-1][0] << "\n";
}
