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
int sieve[10000];

int chain (int x) {
    int ans = 0;
    int old = -1;
    int cur;
    while (x != 1) {
        cur = sieve[x];
        if (cur != old) ans++;
        old = cur;
        x /= cur;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i <= 10000; i++) sieve[i] = i;
    for (int i = 2; i < 1300; i++) {
        if (sieve[i] != i) continue;
        for (int j = i; j < 10000; j += i) {
            sieve[j] = i;
        }
    }
    int ans[6000];
    int c = 0;
    for (int i = 2; i < 6000; i++) {
        if (chain(i) >= 3) ans[c++] = i;
    }
    while (t--) {
        long long n;
        cin >> n;
        cout << ans[n-1] << endl;
    }
}
