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
struct ponto {
    int x, y;

    bool operator< (ponto a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
} pontos[100007];
vi reth;
vi retv;

bool compx (ponto a, ponto b) {
    return a.x < b.x;
}
bool compy (ponto a, ponto b) {
    return a.y < b.y;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m, n != 0) {
        f (n, i) {
            int x, y;
            cin >> x >> y;
            pontos[i].x = x;
            pontos[i].y = y;
        }
        reth.clear ();
        retv.clear ();
        f (m, i) {
            char c, aux;
            int x;
            cin >> c >> aux >> x;
            if (c == 'x') {
                retv.pb (x);
            }
            else {
                reth.pb (x);
            }
        }
        sort (reth.begin (), reth.end ());
        sort (retv.begin (), retv.end ());

        set<ponto> s;

        sort (pontos, pontos+n, compx);
        map<int, ponto> mp;
        int j = 0;
        f (n, i) {
            if (j < retv.size () && retv[j] < pontos[i].x) {
                for (auto p: mp) {
                    s.insert (p.scd);
                }
                mp.clear ();
                j++;
            }
            if (j > 0 && mp.find (pontos[i].y) == mp.end ()) {
                s.insert (pontos[i]);
            }
            mp[pontos[i].y] = pontos[i];
        }
        if (j < retv.size ()) {
            for (auto p: mp) {
                s.insert (p.scd);
            }
        }

        sort (pontos, pontos+n, compy);
        mp.clear ();
        j = 0;
        f (n, i) {
            if (j < reth.size () && reth[j] < pontos[i].y) {
                for (auto p: mp) {
                    s.insert (p.scd);
                }
                mp.clear ();
                j++;
            }
            if (j > 0 && mp.find (pontos[i].x) == mp.end ()) {
                s.insert (pontos[i]);
            }
            mp[pontos[i].x] = pontos[i];
        }
        if (j < reth.size ()) {
            for (auto p: mp) {
                s.insert (p.scd);
            }
        }

        cout << s.size () << endl;
    }
}
