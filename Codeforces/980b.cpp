
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
    if (k == 0) {
        cout << "YES\n";
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << endl;
    }
    else if (k <= n - 2) {
        cout << "YES\n";
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << endl;
        cout << '.';
        k--;
        int bir = k % 2;
        k /= 2;
        for(int j = 0; j < n-2; j++) {
            if(j >= (n-2)/2 - k && j <= (n-2)/2 + k) cout << '#';
            else cout << '.';
        }
        cout << '.';
        cout << endl;
        for(int j = 0; j < n; j++) {
            if(bir && j == n/2) cout << '#';
            else cout << '.';
        }
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
    }
    else if ((k - n + 2) % 2 == 1) {
        cout << "YES\n";
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << endl;
        cout << '.';
        k -= n-2;
        k--;
        k /= 2;
        for(int j = 0; j < n-2; j++) {
            if(j >= (n-2)/2 - k && j <= (n-2)/2 + k) cout << '#';
            else cout << '.';
        }
        cout << '.';
        cout << endl;
        cout << '.';
        for(int j = 0; j < n-2; j++) {
            cout << '#';
        }
        cout << '.';
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
    }
    else {
        cout << "YES\n";
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
        cout << endl;
        cout << '.';
        k -= n - 2;
        k--;
        for(int j = 0; j < n-3; j++) {
            if(j < k) cout << '#';
            else cout << '.';
        }
        cout << '#';
        cout << '.';
        cout << endl;
        cout << '.';
        for(int j = 0; j < n-2; j++) {
            cout << '#';
        }
        cout << '.';
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << '.';
        }
    }
    cout << endl;
}
