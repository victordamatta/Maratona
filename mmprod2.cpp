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
int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int m, ok, k;
        cin >> m >> ok;
        k = ok;
        vi ps;
        vi ns;
        f (m, i) {
            int aux;
            cin >> aux;
            if (aux >= 0) ps.pb (aux);
            else ns.pb (aux);
        }
        int p = ps.size () - 1;
        int n = ns.size () - 1;
        ll ans = 1;
        while (k > 1) {
            if (p < 1 && n < 1) break;
            else if (p < 1) {
                ans = (ans * ns[n] * ns[n-1]) % MOD;
                n -= 2;
            }
            else if (n < 1) {
                ans = (ans * ps[p] * ps[p-1]) % MOD;
                p -= 2;
            }
            else if (ps[p] * ps[p-1] > ns[n] * ns[n-1]) {
                ans = (ans * ps[p] * ps[p-1]) % MOD;
                p -= 2;
            }
            else {
                ans = (ans * ns[n] * ns[n-1]) % MOD;
                n -= 2;
            }
            k -= 2;
        }
        if (k == 1 && p >= 0) ans = (ans * ps[p]) % MOD;
        else if (k != 0) {
            k = ok;
            ans = 1ll;
            p = 0;
            n = 0;
            while (k--) {
                if (p == ps.size ()) {
                    ans = (ans * ns[n]) % MOD;
                    n++;
                }
                else if (n == ns.size ()) {
                    ans = (ans * ps[p]) % MOD;
                    p++;
                }
                else if (abs (ps[p]) < abs (ns[n])) {
                    ans = (ans * ps[p]) % MOD;
                    p++;
                }
                else {
                    ans = (ans * ns[n]) % MOD;
                    n++;
                }
            }
        }
        if (ans < 0) ans += MOD;
        cout << ans << endl;
    }
}
