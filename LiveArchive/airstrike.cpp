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
const long double prec = 0.0000001;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
struct point {
    long double dist;
    int i;

    point (long double dist, int i) : dist(dist), i(i) {}
    bool operator< (point b) const { return dist < b.dist; }
};

long double dist (long double x1, long double y1, long double x2, long double y2) {
    if (x1 == x2 && y1 == y2) {
        return 0.0;
    }
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

long double dtoc (long double r) {
    if (r == 0.0) return 0.0;
    return 3.141 * r;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    long double x1, x2, y1, y2, t;
    int tc = 1;
    while (cin >> n, n != 0) {
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        vector<point> d1;
        vector<point> d2;
        d1.pb (point (0.0, -1));
        f (n, i) {
            long double a, b;
            cin >> a >> b;
            d1.pb (point (dist (x1, y1, a, b), i));
            d2.pb (point (dist (x2, y2, a, b), i));
        }
        sort (d1.begin (), d1.end ());
        sort (d2.begin (), d2.end ());

        set<int> h1;
        long double auxt;
        int mans = 0, cur;
        for (int i = 0; i < d1.size (); i++) {
            auxt = t;
            h1.insert (d1[i].i);
            cur = i;
            auxt -= dtoc (d1[i].dist);
            if (auxt < -prec) break;
            for (int j = 0; j < d2.size (); j++) {
                if (auxt + prec > dtoc (d2[j].dist)) {
                    if (h1.find (d2[j].i) == h1.end ()) {
                        cur++;
                    }
                }
            }
            if (mans < cur) mans = cur;
        }
        cout << tc << ". " << n - mans << endl;
        tc++;
    }
}
