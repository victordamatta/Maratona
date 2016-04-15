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
int pat[4][4], mat[5][5], mat2[5][5];

int ok () {
    int ans = 1, what;
    what = mat[0][0];
    f (4, i) {
        f (4, j) {
            if (mat[i][j] != what) {
                ans = 0;
            }
        }
    }
    return ans;
}

void flip (int x, int y) {
    f (3, i) {
        f (3, j) {
            int a = i + x - 1;
            int b = j + y - 1;
            if (a >= 0 && a < 4) {
                if (b >= 0 && b < 4) {
                    if (pat[i][j]) {
                        mat[a][b] = !mat[a][b];
                    }
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    f (4, i) {
        f (4, j) {
            char c;
            cin >> c;
            if (c == 'W') mat2[i][j] = 1;
            else mat2[i][j] = 0;
        }
    }
    f (3, i) {
        f (3, j) {
            char c;
            cin >> c;
            pat[i][j] = c - '0';
        }
    }
    int conf = 0;
    int mans = OO;
    while (conf < (1<<16)) {
        f (4, i) {
            f (4, j) {
                mat[i][j] = mat2[i][j];
            }
        }
        int cur = 0;
        int aux = 0;
        f (4, i) {
            f (4, j) {
                if (conf & (1 << aux)) {
                    flip (i, j);
                    cur++;
                }
                aux++;
            }
        }
        if (ok () && mans > cur) mans = cur;
        conf++;
    }
    if (mans == OO) cout << "Impossible" << endl;
    else cout << mans << endl;
}
