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
const int OO = 0x3f3f3f;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int n, m;
int mat[37][37];

bool valid (int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

int ans (int x, int y) {
    if (!valid (x, y)) return -100000;
    if (mat[x][y] != 0) return -100000;
    int aux = 0;
    if (valid (x-1, y-1) && mat[x-1][y-1] == 2) {
        mat[x-1][y-1] = 0;
        aux = max (aux, ans (x-2, y-2) + 1);
        mat[x-1][y-1] = 2;
    }
    if (valid (x-1, y+1) && mat[x-1][y+1] == 2) {
        mat[x-1][y+1] = 0;
        aux = max (aux, ans (x-2, y+2) + 1);
        mat[x-1][y+1] = 2;
    }
    if (valid (x+1, y-1) && mat[x+1][y-1] == 2) {
        mat[x+1][y-1] = 0;
        aux = max (aux, ans (x+2, y-2) + 1);
        mat[x+1][y-1] = 2;
    }
    if (valid (x+1, y+1) && mat[x+1][y+1] == 2) {
        mat[x+1][y+1] = 0;
        aux = max (aux, ans (x+2, y+2) + 1);
        mat[x+1][y+1] = 2;
    }
    return aux;
}

int main(){
    std::ios::sync_with_stdio(false);
    while (cin >> n >> m, n != 0) {
        vpi v;
        for (int i = 0; i < n; i++) {
            for (int j = i % 2; j < m; j += 2) {
                cin >> mat[i][j];
                if (mat[i][j] == 1) v.pb (mp (i, j));
            }
        }
        int maxi = 0;
        f (v.size(), i) {
            mat[v[i].fst][v[i].scd] = 0;
            int aux = ans (v[i].fst, v[i].scd);
            mat[v[i].fst][v[i].scd] = 1;
            if (aux > maxi) maxi = aux;
        }
        cout << maxi << "\n";
    }
}
