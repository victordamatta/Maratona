
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 10004;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

struct Point {
    ll x, y;

    Point(ll x, ll y) : x(x), y(y) {};
};

ll n, q;
vector<Point> pts;
vector<ll> area;

ll tri_area(ll a, ll b, ll c) {
    Point A = pts[a];
    Point B = pts[b];
    Point C = pts[c];
    return abs(A.x*B.y + B.x*C.y + C.x*A.y - B.x*A.y - C.x*B.y - A.x*C.y);
}

int main(){
    std::ios::sync_with_stdio(false);
    bool first = true;
    while(cin >> n >> q, n != 0) {
        if(!first) cout << endl;
        first = false;
        for(ll i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            pts.pb(Point(x, y));
        }

        area.pb(0);
        for(ll i = 1; i + 1 < n; i++) {
            ll ar = tri_area(0, i, i + 1);
            area.pb(ar + area[i-1]);
        }
        area.pb(0);

        ll total = area[n-2];
        for(ll i = 0; i < q; i++) {
            ll a, b;
            cin >> a >> b;
            ll cand;
            if(a == 0) cand = area[b-1];
            else cand = tri_area(0, a, b) + area[a-1] + (total - area[b-1]);
            ll ans = min(cand, total - cand);
            if(ans % 2 == 0)
                cout << ans/2 << ".0" <<  endl;
            else
                cout << ans/2 << ".5" << endl;
        }
        pts.clear();
        area.clear();
    }
}
