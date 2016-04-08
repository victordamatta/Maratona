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
int mat[107][107];
int mat2[107][107];
int n, maxi;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> maxi;
    ms (mat, 0);
    ms (mat2, 0);
    f (maxi, i) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = c;
    }
    
    int ansx, ansy, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (mat[i][j] != 0) {
                        if (abs (i-k) + abs (j-l) == mat[i][j]) {
                            mat2[k][l]++;
                            if (mat2[k][l] == maxi) {
                                ans++;
                                ansx = k;
                                ansy = l;
                            }
                        }
                    }
                }
            }
        }
    }
    if (ans != 1) cout << "-1 -1\n";
    else cout << ansx << " " << ansy << "\n";
}
