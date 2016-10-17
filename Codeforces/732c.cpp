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
    ll b, d, s;
    cin >> b >> d >> s;
    ll mini = min (b, min (d, s)) / 3;
    b -= mini * 3;
    d -= mini * 3;
    s -= mini * 3;

    ll maxi = max (b, max (d, s));
    ll ans;
    ans = (maxi - b) + (maxi - d) + (maxi - s);
    if (maxi == b && maxi == d) {
        ans--;
    }
    else if (maxi == b && maxi == s) {
        ans--;
    }
    else if (maxi == d && maxi == s) {
        ans--;
    }
    else ans -= 2;
    ans = max (ans, 0ll);
    cout << ans << endl;
}
