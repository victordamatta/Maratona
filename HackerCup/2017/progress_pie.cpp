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
    int t;
    cin >> t;
    int cx = 0;
    int cy = 50;
    f (t, k) {
        int p, x, y;
        cin >> p >> x >> y;

        int vx = x - 50;
        int vy = y - 50;

        double cosi = (double) (cx*vx + cy*vy) / (sqrt (cx*cx + cy*cy) * sqrt (vx*vx + vy*vy));
        double angle = acos (cosi);
        angle = (angle / (2 * M_PI)) * 360;
        if (vx < 0) angle = 360 - angle;

        cout << "Case #" << k+1 << ": ";
        double desired = (double) p/100.0;
        desired *= 360;
        if (desired > angle && vx*vx + vy*vy <= 2500) cout << "black\n";
        else cout << "white\n";
    }
}
