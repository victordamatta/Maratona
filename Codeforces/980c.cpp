
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
#define int long long
using namespace std;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 10004;
const int MOD = 1000000007;
const int OO = INT_MAX;
inline int mod(int x) { return x % MOD; }

int32_t main(){
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> color(256);
    for(int i = 0; i < 256; i++) color[i] = -1;

    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        bool done = false;
        for(int i = p; i < 256; i++) {
            if(color[i] != -1 && color[i] <= p) {
                cout << color[i] << ' ';
                done = true;
                break;
            }
        }
        if(done) continue;
        color[p] = p;
        for(int i = p - 1; i >= max(p - k + 1, 0ll); i--) {
            if(color[i] != -1) {
                if (p - color[i] < k) {
                    color[p] = color[i];
                    break;
                }
                else {
                    color[p] = i+1;
                    break;
                }
            }
            else color[p] = i;
        }
        color[color[p]] = color[p];
        cout << color[p] << ' ';
    }
    cout << endl;
}
