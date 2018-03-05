
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
    set<int> s;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if (x > 0)
            s.insert(x);
    }
    cout << s.size() << endl;
}

