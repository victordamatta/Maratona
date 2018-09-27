
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
    int x;
    cin >> x;
    string moves;
    cin >> moves;
    int it = 0;
    int ans = 0;
    while(it < moves.size()) {
        ans++;
        if(it+1 < moves.size() && moves[it] != moves[it+1]) it += 2;
        else it += 1;
    }
    cout << ans << endl;
}
