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
int n, t;
int vpd[20][5000];
int buttons[20];

int pd (int k, int t0) {
    if (k == n && t0 < t) return OO;
    if (k == n) return 0;
    if (vpd[k][t0] != -1) return vpd[k][t0];

    //if (buttons[k] < 0 && t0 == 0) vpd[k][t0] = pd (k + 1, t0);

    vpd[k][t0] = min (1 + pd (k, t0 + buttons[k]), pd (k + 1, t0));

    return vpd[k][t0];
}

int main(){
    std::ios::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        f (n, i) cin >> buttons[i];
    }
    cout << pd (0, 0);
}
