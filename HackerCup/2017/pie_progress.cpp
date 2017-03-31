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
int t, n, m;
ll vpd[307][307][307];
ll pies[307][307];
int ex[307];

ll pd (int d, int k, int p) {
    if (p >= n - d + 1) return 0;
    if (p < 0) return OO;
    if (d > n) return OO;
    if (k >= m) return OO;
    if (vpd[d][k][n] != -1) return vpd[d][k][n];

    ll ans = OO;
    ans = min (ans, pies[d][k] + pd (d, k + 1, p + 1));
    ans = min (ans, pies[d][k] + pd (d + 1, 0, p));
    ans = min (ans, pd (d + 1, 0, p - 1));

    vpd[d][k][p] = ans;

    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> t;
    f (301, i) ex[i] = i*i;
    for (int i = 300; i > 0; i--) ex[i] -= ex[i-1];
    f (t, k) {
        cin >> n >> m;
        f (n, i) {
            f (m, j) {
                cin >> pies[i+1][j];
            }
        }
        f (n, i) sort (pies[i+1], pies[i+1] + m);
        f (n, i) {
            f (m, j) {
                pies[i+1][j] += ex[j+1];
            }
        }
        ms (vpd, -1);
        ll ans = pd (1, 0, 0);
        cout << "Case #" << k+1 << ": " << ans << endl;
    }
}
