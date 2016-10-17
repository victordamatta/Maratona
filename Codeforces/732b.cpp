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
    int n, k;
    cin >> n >> k;
    int pd, d;
    int ans = 0;
    vi vans;
    cin >> pd;
    vans.pb (pd);
    f (n-1, i) {
        cin >> d;
        int change = max (k - d - pd, 0);
        ans += change;
        d += change;
        vans.pb (d);
        pd = d;
    }
    cout << ans << endl;
    for (int i = 0; i <vans.size (); i++) cout << vans[i] << " ";
    cout << endl;
}
