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

ll expf (ll e, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return expf (e*e % MOD, n/2) % MOD;
    else return e * expf (e, n - 1) % MOD;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        int mi = OO, ma = -1;
        vector<int> mini;
        vector<int> maxi;
        f(n, i) {
            int x;
            cin >> x;
            mi = min (mi, x);
            ma = max (ma, x);
            v.pb (x);
        }
        if (mi == ma) {
            ll ans1 = (((n+1)*n)/2) % MOD;
            ll ans2 = (expf (2, n) - 1) % MOD;
            cout << ans1 << " " << ans2 << endl;
            continue;
        }
        f (n, i) {
            if (v[i] == mi) mini.pb (i);
            if (v[i] == ma) maxi.pb (i);
        }
        int ans1 = 0, ans2 = 0;
        f (n, k) {
            vi::iterator vit1 = lower_bound (maxi.begin (), maxi.end (), k);
            vi::iterator vit2 = lower_bound (mini.begin (), mini.end (), k);
            int last = n;
            if (vit1 != maxi.end () && vit2 != mini.end ()) 
                last = max (*vit2, *vit1);
            ans1 += n - last;
            ans1 %= MOD;
        }

        ans2 += ((expf (2, n) + expf (2, n - mini.size () - maxi.size ()))%MOD - (expf (2, n - mini.size ()) + expf (2, n - maxi.size ()))%MOD + MOD);
        ans2 %= MOD;

        cout << ans1 << " " << ans2 << endl;
    }
}
