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
int grid[107][107];
int tgrid[107][107];
vector<string> ans;

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    int mvs = 0;
    string mini = "row ";
    string maxi = "col ";

    cin >> n >> m;

    f (n, i) {
        f (m, j) {
            cin >> grid[i][j];
            tgrid[i][j] = grid[i][j];
        }
    }

    if (m < n) {
        swap (mini, maxi);
        f (n, i) {
            f (m, j) {
                tgrid[j][i] = grid[i][j];
            }
        }
        swap (n, m);
    }

    f (n, i) {
        int mn = OO;
        f (m, j) {
            mn  = min (mn, tgrid[i][j]);
        }
        if (mn > 0) {
            f (m, j) {
                tgrid[i][j] -= mn;
            }
            mvs += mn;
            f (mn, k) {
                ans.pb (mini + to_string(i+1));
            }
        }
    }
    f (m, j) {
        int mn = OO;
        f (n, i) {
            mn  = min (mn, tgrid[i][j]);
        }
        if (mn > 0) {
            f (n, i) {
                tgrid[i][j] -= mn;
            }
            mvs += mn;
            f (mn, k) {
                ans.pb (maxi + to_string(j+1));
            }
        }
    }

    bool ok = true;
    f (n, i) {
        f (m, j)  {
            if (tgrid[i][j] != 0) ok = false;
        }
    }

    if (ok) {
        cout << mvs << endl;
        for (string s : ans) {
            cout << s << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
}
