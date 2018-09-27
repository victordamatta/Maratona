
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

int field[108][108];
int ans[108][108];
int n, k;

bool ok(int x, int y) {
    return (x < n) && (y < n) && (field[x][y]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if(c == '.') field[i][j] = 1;
            else field[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool okv = true;
            bool okh = true;
            for(int s = 0; s < k; s++) {
                okv = okv && ok(i + s, j);
                okh = okh && ok(i, j + s);
            }

            for(int s = 0; s < k; s++) {
                ans[i+s][j] += (int)okv;
                ans[i][j+s] += (int)okh;
            }
        }
    }
    int maxv, maxi, maxj;
    maxv = maxi = maxj = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (ans[i][j] > maxv) {
                maxv = ans[i][j];
                maxi = i;
                maxj = j;
            }
        }
    }
    cout << maxi+1 << " " << maxj+1 << endl;
}
