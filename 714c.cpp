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

ll ntop (ll x) {
    ll pat = 0;
    ll multi = 1;
    while (x > 0) {
        if ((x%10)%2 == 0) pat += 0;
        else pat += multi;
        multi *= 10;
        x /= 10;
    }
    return pat;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    map<ll, ll> ans;
    f (t, i) {
        char c;
        ll aux;
        cin >> c;
        cin >> aux;
        if (c == '+')
            ans[ntop (aux)]++;
        else if (c == '-')
            ans[ntop (aux)]--;
        else
            cout << ans[ntop (aux)] << endl;
    }
}
