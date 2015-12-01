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
const int OO = 0x3f3f3f;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    double m[10], w[10], hs, hu;
    double v[] = {500, 1000, 1500, 2000, 2500};
    f(5, i) cin >> m[i];
    f(5, i) cin >> w[i];
    cin >> hs >> hu;
    double ans = 0;
    f(5, i) ans += max (0.3 * v[i], (1-(double)m[i]/250)*v[i] - 50*w[i]);
    ans += 100*hs;
    ans -= 50*hu;
    cout << ans << "\n";
}
