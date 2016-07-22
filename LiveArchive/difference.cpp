
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
    int a, b, c, d;
    int ans;
    while (cin >> a >> b >> c >> d, a != 0 || b != 0 || c != 0 || d != 0) {
        ans = 0;
        int ta, tb, tc, td;
        while (a != b || a != c || a != d || b != c || b != d || c != d) {
            ta = abs (a-b);
            tb = abs (c-b);
            tc = abs (c-d);
            td = abs (a-d);
            a = ta;
            b = tb;
            c = tc;
            d = td;
            ans++;
        }
        cout << ans << endl;
    }
}
