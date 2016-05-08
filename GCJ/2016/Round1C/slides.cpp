#include <bits/stdc++.h>
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
int graph[10][10];
int deg[10];
int ps[10];
ll n, m;

int now () {
    vi topo;
    int mk[10];
    ms (mk, 0);
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += graph[j][i];
        }
        deg[i] = degree;
    }
    while (topo.size () < n) {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0 && !mk[i]) {
                ok = true;
                mk[i] = 1;
                topo.pb (i);
                for (int j = 0; j < n; j++) {
                    if (graph[i][j]) {
                        deg[j]--;
                    }
                }
            }
        }
        if (!ok) {
            return 0;
        }
    }
    ps[n-1] = 1;
    for (int i = topo.size()-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (graph[topo[i]][j]) {
                ps[topo[i]] += ps[j];
            }
        }
    }
}

ll Pow (ll x) {
    if (x == 0ll) return 1ll;
    return 2 * Pow (x-1);
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    f (t, k) {
        cin >> n >> m;
        ll brute = 0;
        bool pos = false;
        ll ways = Pow (n*n - 2*n) + 1;
        while (brute < ways) {
            ms (deg, 0);
            ms (ps, 0);
            ll aux = brute;
            for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    graph[i][j] = aux % 2;
                    aux /= 2;
                }
            }
            now ();
            if (ps[0] == m) {
                pos = true;
                break;
            }
            brute += 1ll;
        }
        cout << "Case #" << k+1 << ": ";
        if (pos) {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << graph[i][j];
                    if (j != n-1) cout << " ";
                }
                cout << endl;
            }
            /* for (int i = topo.size()-1; i >= 0; i--) { */
            /*     cout << topo[i] << " " << ps[topo[i]] << "         "; */
            /* } */
            /* cout << endl; */
        }
        else cout << "IMPOSSIBLE" << endl;
    }
}
