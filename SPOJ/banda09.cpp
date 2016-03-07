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

int main(){
    std::ios::sync_with_stdio(false);
    int n, m, a, b, c;
    int mat[107][107];
    cin >> n >> m;
    ms (mat, 0);
    while (m--) {
        cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c;
    }
    int maxi = 0, aux;
    a = 1, b = 2, c = 3;
    for (int i = 1; i <= n-2; i++) {
        for (int j = i+1; j <= n-1; j++) {
            for (int k = j+1; k <= n; k++) {
                aux = 0;
                aux += mat[i][j];
                aux += mat[k][j];
                aux += mat[i][k];
                if (aux > maxi) {
                    a = i;
                    b = j;
                    c = k;
                    maxi = aux;
                }
            }
        }
    }
    cout << a << " " << b << " " << c << "\n";
}
