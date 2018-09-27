
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
    string s;
    cin >> s;
    int links = 0;
    int pearls = 0;
    for (char c : s) {
        if(c == '-') links++;
        else pearls++;
    }
    if(pearls == 0 || links % pearls == 0) cout << "YES\n";
    else cout << "NO\n";
}
