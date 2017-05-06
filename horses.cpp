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

const double eps = 1e-6;

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    f (t, k) {
        int d, n;
        cin >> d >> n;
        vector<pair<int, double> > horses;
        f (n, i) {
            int a;
            double b;
            cin >> a >> b;
            horses.pb (mp (a, b));
        }

        double lo = 0.0;
        double hi = 10000000000001.0;
        for (int time = 0; time < 100; time++) {
            double mid = (lo + hi) / 2;
            //cout << lo << " " << hi << " " << mid << endl;

            double mt = d / mid;

            bool ok = true;
            for (int i = 0; i < n; i++) {
                double ct = (d - horses[i].fst) / horses[i].scd;

                if (mt < ct) ok = false;
            }

            if (ok) lo = mid;
            else hi = mid - eps;
        }

        cout << fixed;
        cout << setprecision(6) << "Case #" << k+1 << ": " << (hi + lo) / 2 << endl;
    }
}
