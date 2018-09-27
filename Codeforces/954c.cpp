
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

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> path;
    int jmp = -1;
    int px = -1;
    int maxi = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        path.pb(x);

        if(x == px) goto no;
        else if(px != -1 && abs(x - px) > 1) {
            if(jmp == -1) jmp = abs(x - px);
            else if(jmp != abs(x - px)) goto no;
        }

        px = x;
        maxi = max(maxi, x);
    }

    if(jmp == -1) {
        cout << "YES" << endl;
        cout << 1 << " " << maxi << endl;
        return 0;
    }
    else {
        int pi, pj;
        pi = pj = -1;
        for(int x : path) {
            int i, j;
            j = x % jmp;
            if(j == 0) j += jmp;
            i = (x - j) / jmp + 1;

            if(pi != -1 && abs(i - pi) + abs(j - pj) != 1) goto no;

            pi = i;
            pj = j;
        }
        cout << "YES" << endl;
        cout << maxi << " " << jmp << endl;
        return 0;
    }

no:
    cout << "NO" << endl;
}
