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
    int mil = 10, mid = 10, mal = 0, mad = 0;
    int n;
    cin >> n;
    f (n, i) {
        char c;
        cin >> c;
        int x = c - '0';
        if (x == 1 || x == 4 || x == 7) mil = min (mil, 1), mal = max (mal, 1);
        else if (x == 2 || x == 5 || x == 8 || x == 0) mil = min (mil, 2), mal = max (mal, 2);
        else if (x == 3 || x == 6 || x == 9) mil = min (mil, 3), mal = max (mal, 3);
        if (x == 1 || x == 2 || x == 3) mid = min (mid, 1), mad = max (mad, 1);
        else if (x == 4 || x == 5 || x == 6) mid = min (mid, 2), mad = max (mad, 2);
        else if (x == 7 || x == 8 || x == 9) mid = min (mid, 3), mad = max (mad, 3);
        else mid = min (mid, 4), mad = max (mad, 4);
    }

    if ((mad - mid < 2 || mal - mil < 2) && (mad - mid < 3)) {
        cout << "NO\n";
    }
    else cout << "YES\n";
}
