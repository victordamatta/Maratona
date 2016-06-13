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
int a[100007];

bool comp (int x, int y) {
    return abs (x) < abs (y);
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        f (n, i) cin >> a[i];

        sort (a, a+n, comp);

        int par = 0;
        for (int i = n-k; i < n; i++) {
            if (a[i] < 0) par++;
        }
        if (par % 2 != 0) {
            int bp, bn, sp, sn;
            bp = bn = sp = sn = OO;
            for (int i = n-k; i < n; i++) {
                if (a[i] > 0) {
                    bp = i;
                    break;
                }
            }
            for (int i = n-k-1; i >= 0; i--) {
                if (a[i] > 0) {
                    sp = i;
                    break;
                }
            }
            for (int i = n-k; i < n; i++) {
                if (a[i] < 0) {
                    bn = i;
                    break;
                }
            }
            for (int i = n-k-1; i >= 0; i--) {
                if (a[i] < 0) {
                    sn = i;
                    break;
                }
            }
            if ((bp == OO || sn == OO) && (bn == OO || sp == OO)) {
                ll ans = 1;
                for (int i = 0; i < k; i++) {
                    ans = (ans * a[i]) % MOD;
                }
                if (ans < 0) ans += MOD;
                cout << ans << endl;
                continue;
            }
            else {
                if (bp == OO || sn == OO) swap (a[bn], a[sp]);
                else if (bn == OO || sp == OO) swap (a[bp], a[sn]);
                else {
                    ll op1 = bn * sn;
                    ll op2 = bp * sp;
                    if (op1 > op2) swap (a[sn], a[bp]);
                    else swap (a[sp], a[bn]);
                }
            }
        }
        ll ans = 1;
        for (int i = n-k; i < n; i++) {
            ans = (ans * a[i]) % MOD;
        }
        if (ans < 0) ans += MOD;
        cout << ans << endl;
    }
}
