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
const ll MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
ll power (ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    if (b % 2 == 0) {
        return power ((a*a) % MOD, b/2);
    }
    else {
        return (a * power (a, b-1)) % MOD;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    ll a;
    cin >> a;
    cout << power (2, a) % MOD;
}
