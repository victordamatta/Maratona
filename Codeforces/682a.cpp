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
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll> > vpi;
typedef set<ll> si;
typedef set<ll>::iterator sit;
const ll MOD = 1000000007;
const ll OO = 1000000000;
//REMEMBER LONG LONG ll
//REMEMBER TO INITIALZE THINGS

ll ns[5];
ll ms[5];

int main(){
    std::ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    f (n, i) {
        ns[(i+1)%5]++;
    }
    f (m, i) {
        ms[(i+1)%5]++;
    }
    cout << ns[0]*ms[0] + ns[1]*ms[4] + ns[2]*ms[3] + ns[3]*ms[2] + ns[4]*ms[1] << endl;
}
