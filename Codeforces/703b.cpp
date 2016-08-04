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
int beauty[100007];

int main(){
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    ll caps = 0;
    set<int> s;
    ll ans = 0;
    f (n, i) cin >> beauty[i];
    f (k, i) {
        int aux;
        cin >> aux;
        s.insert (aux-1);
        ans += beauty[aux-1] * caps;
        caps += beauty[aux-1];
    }

    f (n-1, i) {
        if (s.find (i) != s.end ()) continue;
        ans += beauty[i] * caps;
        if (s.find (i+1) == s.end ()) 
            ans += beauty[i] * beauty[i+1];
    }
    if (s.find (n-1) == s.end ()) {
        ans += beauty[n - 1] * caps;
        if (s.find (0) == s.end ()) 
            ans += beauty[n-1] * beauty[0];
    }

    cout << ans << endl;
}
