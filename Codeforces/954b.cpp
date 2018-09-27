
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
    string s;
    cin >> s;
    for(int i = s.size()/2; i >= 1; i--) {
        bool rep = true;
        for(int j = 0; j < i; j++)
            if(s[j] != s[i+j]) rep = false;

        if(rep) {
            cout << i + 1 + (s.size() - 2*i) << endl;
            return 0;
        }
    }
    cout << s.size() << endl;
}
