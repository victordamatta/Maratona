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

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    int a, b, c, d;
    cin >> n >> m;
    cin >> a >> b >> c >> d;
    if (m < n+1 || n == 4) cout << -1 << endl;
    else {
        vi path;
        path.pb (a);
        path.pb (c);
        for (int i = 1; i <= n; i++) {
            if (i != a && i != b && i != c && i != d) {
                path.pb (i);
            }
        }
        path.pb (d);
        path.pb (b);
        for (int x: path) {
            cout << x << " ";
        }
        cout << endl;
        cout << c << " ";
        cout << a << " ";
        for (int i = 2; i <= n; i++) {
            if (path[i] == d) break;
            cout << path[i] << " ";
        }
        cout << b << " ";
        cout << d << endl;
    }
}
