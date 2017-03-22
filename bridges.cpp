#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=1; let<=x; let++)
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
int n, m, f, t, q;
int bi, bj, qbi, qbj, fi, fj, qfi, qfj;
int v;
map<pi, int> mm;
int dist[300][300];
pi vertex[300];

int main() {
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> f >> m;
        mm.clear ();
        v = 1;
        f (n, i) {
            vertex[v] = mp(i, 1);
            mm[mp(i, 1)] = v++;
        }
        f (300, i) {
            f (300, j) {
                dist[i][j] = OO;
            }
        }
        f (n-1, i) {
            int ui = mm[mp(i, 1)], uj = mm[mp(i+1, 1)];
            dist[ui][uj] = 1;
            dist[uj][ui] = 1;
        }
        int ui = mm[mp(n, 1)], uj = mm[mp(1, 1)];
        dist[ui][uj] = 1;
        dist[uj][ui] = 1;
        f (m, i) {
            cin >> bi >> fi >> bj >> fj >> t;
            if (mm.find (mp (bi, fi)) == mm.end ()) {
                vertex[v] = mp(bi, fi);
                mm[mp(bi, fi)] = v++;
            }
            if (mm.find (mp (bj, fj)) == mm.end ()) {
                vertex[v] = mp(bj, fj);
                mm[mp(bj, fj)] = v++;
            }
            int ui = mm[mp(bi, fi)], uj = mm[mp(bj, fj)];
            int basei = mm[mp(bi, 1)], basej = mm[mp(bj, 1)];

            dist[ui][basei] = min (dist[ui][basei], fi - 1);
            dist[basei][ui] = min (dist[basei][ui], fi - 1);
            dist[uj][basej] = min (dist[uj][basej], fj - 1);
            dist[basej][uj] = min (dist[basej][uj], fj - 1);

            dist[ui][uj] = min (dist[ui][uj], t);
            dist[uj][ui] = min (dist[uj][ui], t);
        }

        f (v-1, i) {
            f (v-1, j) {
                int ui = mm[vertex[i]], uj = mm[vertex[j]];
                if (vertex[i].fst == vertex[j].fst) {
                    dist[ui][uj] = abs (vertex[i].scd - vertex[j].scd);
                }
            }
        }

        f (v-1, i) {
            f (v-1, j) {
                f (v-1, k) {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        f (v-1, i) {
            f (v-1, j)
                cout << dist[i][j] << ' ';
            cout << endl;
        }
        cout << endl;

        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> qbi >> qfi >> qbj >> qfj;
            int ui = OO, uci, uj = OO, ucj, di = -1, dci, dj = -1, dcj;
            for (int j = 1; j < v; j++) {
                /* cout << vertex[j].fst << ' ' << vertex[j].scd << endl; */
                if (vertex[j].fst == qbi) {
                    if (vertex[j].scd >= qfi && vertex[j].scd < ui) {
                        ui = vertex[j].scd;
                        uci = abs (vertex[j].scd - qfi);
                    }
                    if (vertex[j].scd <= qfi && vertex[j].scd > di) {
                        di = vertex[j].scd;
                        dci = abs (vertex[j].scd - qfi);
                    }
                }
                if (vertex[j].fst == qbj) {
                    if (vertex[j].scd >= qfj && vertex[j].scd < uj) {
                        uj = vertex[j].scd;
                        ucj = abs (vertex[j].scd - qfj);
                    }
                    if (vertex[j].scd <= qfj && vertex[j].scd > dj) {
                        dj = vertex[j].scd;
                        dcj = abs (vertex[j].scd - qfj);
                    }
                }
            }
            cout << endl;
            cout << mm[mp(qbi, qfi)] << " (" << qbi << ' ' << qfi << ") ";
            cout << "Sup: (" << qbi << ',' << ui << ") -> " << uci << " Inf: (" << qbi << ',' << di << ") -> " << dci << endl;
            cout << mm[mp(qbj, qfj)] << " (" << qbj << ' ' << qfj << ") ";
            cout << "Sup: (" << qbj << ',' << uj << ") -> " << ucj << " jnf: (" << qbj << ',' << dj << ") -> " << dcj << endl;
            int ans = OO;
            ans = min (ans, uci + dist[mm[mp (qbi, ui)]][mm[mp(qbj, uj)]] + ucj);
            ans = min (ans, uci + dist[mm[mp (qbi, ui)]][mm[mp(qbj, dj)]] + dcj);
            ans = min (ans, dci + dist[mm[mp (qbi, di)]][mm[mp(qbj, uj)]] + ucj);
            ans = min (ans, dci + dist[mm[mp (qbi, di)]][mm[mp(qbj, dj)]] + dcj);

            cout << ans << endl;
        }
    }
}
