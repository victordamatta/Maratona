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
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
vi graph[10007];
pi damage[10007];

int dmg (int v, int p) {
    if (graph[v].size () > 1 && p == -1) return 0;
    if (graph[v].size () > 2) return 0;

    int ans = 1;
    for (int u : graph[v]) {
        if (u != p)
            ans += dmg (u, v);
    }
    return ans;
}

bool cmp (pi a, pi b) {
    return a.scd < b.scd;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        f (n, i) graph[i+1].clear ();

        f (m, i) {
            int a, b;
            cin >> a >> b;
            graph[a].pb (b);
            graph[b].pb (a);
        }

        f (n, i) {
            damage[i+1].fst = i+1;
            damage[i+1].scd = 0;
        }

        f (n, i) {
            damage[i+1].scd = dmg (i+1, -1);
        }

        sort (damage + 1, damage + n + 1, cmp);
        /*
        for (int i = 1; i <= n; i++) {
            cout << damage[i].fst << " " << damage[i].scd << endl;
        }
        */

        int ans = 0;
        for (int i = n - k; i > 0; i--) ans += damage[i].scd;
        cout << ans << endl;
    }
}
