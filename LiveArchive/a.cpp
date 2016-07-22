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
int dif (string a, string b) {
    int ans = 0;
    f(a.length (), i) ans += a[i] != b[i];
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    vector<string> v;
    f (n, i) {
        string s;
        cin >> s;
        v.pb (s);
    }
    f (q, i) {
        bool nf = true;
        string s;
        cin >> s;
        for (string ss : v) {
            if (dif (s, ss) <= k) {
                cout << "S\n";
                nf = false;
                break;
            }
        }
        if (nf) cout << "N\n";
    }
}
