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

int main(){
    std::ios::sync_with_stdio(false);
    int test;
    cin >> test;
    f (test, t) {
        string s;
        int k;
        cin >> s >> k;
        int ans = 0;
        for (int i = 0; i <= s.size () - k; i++) {
            if (s[i] == '-') {
                ans++;
                for (int j = i; j < i + k; j++) {
                    if (s[j] == '-') s[j] = '+';
                    else s[j] = '-';
                }
            }
        }

        bool ok = true;
        f (s.size (), i) {
            if (s[i] == '-') {
                ok = false;
                break;
            }
        }

        cout << "Case #" << t+1 << ": ";
        if (ok) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
}
