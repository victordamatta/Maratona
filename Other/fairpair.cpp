#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
*/
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
int st[1007], ts[1007];
int codec[1007];

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        f (n, i) cin >> st[i];
        f (n, i) {
            cin >> ts[i];
            codec[i] = ts[i];
        }

        f (n, i) {
            if (st[i] != ts[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (st[j] != ts[j]) continue;
                if (st[i] != st[j]) {
                    swap (ts[i], ts[j]);
                    break;
                }
            }
        }
        f (n, i) {
            if (st[i] != ts[i]) continue;
            f (n, j) {
                if (ts[i] != st[j] && ts[j] != st[i]) {
                    swap (ts[i], ts[j]);
                    break;
                }
            }
        }
        int ans = 0;
        f (n, i) {
            if (st[i] == ts[i]) ans++;
        }
        vi arr;
        f (n, i) {
            f (n, j) {
                if (codec[j] == ts[i]) {
                    arr.pb (j);
                    codec[j] = 0;
                    break;
                }
            }
        }

        cout << ans << endl;
        cout << arr[0]+1;
        f (n-1, i) cout << " " << arr[i+1]+1;
        cout << endl;
    }
}
