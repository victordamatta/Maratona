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
int n, k;
int price[100007];
int tax[100007];
int vpd[100001][501][2];

int pd (int i, int l, int h) {
    if (h < 0 || h > 1) return -OO;
    if (l < 0) return -OO;
    if (i == n) return 0;

    vpd[i][l][k] = max (max (price[i] + tax[i] + pd (i+1, l-1, h-1), -price[i] + pd (i+1, l, h+1)), pd (i+1, l, h));
    if (h == 1) vpd[i][l][k] = max (vpd[i][l][k], tax[i] + pd (i+1, l-1, h));
    return vpd[i][l][k];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    f (n, i) cin >> price[i];
    f (n-1, i) cin >> tax[i+1];
    int ans = pd (0, k, 0);
    cout << ans << endl;
}
