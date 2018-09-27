
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

vector<string> mat(507);
int r, c;
int sx[] = {0, 1, 0, -1};
int sy[] = {1, 0, -1, 0};

int pad(int i, int j) {
    for(int x = 0; x < 4; x++) {
        int ni = i + sx[x];
        int nj = j + sy[x];
        if(i + sx[x] >= 0 && i + sx[x] < r) {
            if(j + sy[x] >= 0 && j + sy[x] < c) {
                if(mat[ni][nj] == 'W') {
                    return 1;
                }
                else if(mat[ni][nj] == '.')
                    mat[ni][nj] = 'D';
            }
        }
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        mat[i] = s;
    }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(mat[i][j] == 'S')
                if(pad(i, j))
                    goto error;

    cout << "Yes" << endl;
    for(int i = 0; i < r; i++) {
        cout << mat[i] << endl;
    }

    return 0;
error:
    cout << "No" << endl;
    return 0;
}
