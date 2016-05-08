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

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    f (t, k) {
        int n;
        int ps[30];
        int zs = 0;
        int sum = 0;
        cin >> n;
        f (n, i) {
            cin >> ps[i];
            sum += ps[i];
        }
        ps[n] = 10000;
        vpi ans;
        while (zs < n) {
            f (n+1, i) {
                f (n+1, j) {
                    bool ok = true;
                    ps[i]--;
                    ps[j]--;
                    int psum = sum;
                    if (i != n) sum--;
                    if (j != n) sum--;
                    if (ps[i] < 0 || ps[j] < 0) ok = false;
                    for (int x = 0; x < n; x++) {
                        if (ps[x] > sum/2) ok = false;
                    }
                    if (ok) {
                        ans.pb (mp (i, j));
                        if (ps[i] == 0) zs++;
                        if (i != j && ps[j] == 0) zs++;
                    }
                    else {
                        ps[i]++;
                        ps[j]++;
                        sum = psum;
                    }
                }
            }
        }
        cout << "Case #" << k+1 << ":";
        for (int i = 0; i < ans.size (); i++) {
            pi p = ans[i];
            char c = 0, d = 0;
            if (p.fst != n)
                c = 'A' + p.fst;
            if (p.scd != n)
                d = 'A' + p.scd;
            if (c != 0 && d != 0)
                cout << " " << c << d;
            else if (c!= 0)
                cout << " " << c;
            else if (d != 0)
                cout << " " << d;
        }
        cout << endl;
    }
}
