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
#define all(x) x.begin(), x.end()
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

pi n = mp (0, 1);
pi s = mp (0, -1);
pi w = mp (-1, 0);
pi e = mp (1, 0);

int norm (int x) {
    if (x == 0) return x;
    if (x > 0) return 1;
    return -1;
}

bool curve (pi a, pi b, pi dir) {
    if (dir.fst == norm(b.fst - a.fst) && dir.scd == norm(b.scd - a.scd)) return true;
    return false;
}

bool op (pi a, pi b) {
    if (a.fst == -b.fst && a.scd == -b.scd) return true;
    return false;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    pi cur, next;
    cin >> cur.fst >> cur.scd;
    pi lake = e;
    int ans = 0;
    f (t, i) {
        cin >> next.fst >> next.scd;
        if (curve (next, cur, n)) {
            if (op (lake, n)) ans++;
            lake = e;
        }
        else if (curve (next, cur, s)) {
            if (op (lake, s)) ans++;
            lake = w;
        }
        else if (curve (next, cur, e)) {
            if (op (lake, e)) ans++;
            lake = s;
        }
        else {
            if (op (lake, w)) ans++;
            lake = n;
        }
        cur = next;
    }
    cout << ans << "\n";
}
