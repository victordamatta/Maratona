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

int Fat (int a) {
    if (a == 1) return 1;
    return ((long long) a * Fat (a - 1)) % MOD;
}

int Pow (int b, int e) {
    if (e == 0) return 1;
    if (e % 2 == 0) return Pow (((long long) b*b)%MOD, e/2);
    return ((long long) b * Pow (b, e-1)) % MOD;
}

int main(){
    int n, m;
    cin >> n >> m;

    int a = Pow (n+1, m) % MOD;
    int b = Fat (m) % MOD;
    b = Pow (b, 1000000005) % MOD;
    ll ans = ((long long) a * b) % MOD;
    cout << ans << endl;
}
