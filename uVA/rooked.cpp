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
int n;
int mat[6][6], e = 0;
pi stc[20];

bool valid (int a, int b) {
    int xabu = 0;
    if (mat[a][b]) {
        for (int i = 0; i < e; i++) {
            pi aux = stc[i];
            if (aux.fst == a) {
                xabu = 1;
                for (int j = min (stc[i].scd, b); j < max (stc[i].scd, b); j++) {
                    if (mat[a][j] == 0)
                        xabu = 0;
                }
            } else if (aux.scd == b) {
                 xabu = 1;
                for (int j = min (stc[i].fst, a); j < max (stc[i].fst, a); j++) {
                    if (mat[j][b] == 0)
                        xabu = 0;
                }
            }
            if (xabu) return false;
        }
        return true;
    }
    else {
        return false;
    }
}

void advance (int* a, int* b) {
    *b += 1;
    if (*b == n) {
        *b = 0;
        *a += 1;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    while (cin >> n, n != 0) {
        e = 0;
        ms (stc, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                if (c == '.') mat[i][j] = 1;
                else mat[i][j] = 0;
            }
        }
        int i, j, ans = 0, aux = 1;
        stc[0] = mp (0, -1);
        e++;
        while (e > 0) {
            e--;
            aux--;
            i = stc[e].fst;
            j = stc[e].scd;
            advance (&i, &j);
            while (i < n) {
                while (j < n) {
                    if (valid (i, j)) {
                        stc[e] = mp (i, j);
                        e++;
                        aux++;
                    }
                    j++;
                }
                j = 0;
                i++;
            } 
            if (aux > ans) ans = aux;
        }
        cout << ans << "\n";
    }
}
