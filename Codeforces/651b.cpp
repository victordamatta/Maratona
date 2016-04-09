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
const int MOD = 1000000007;
const int OO = 0x3f3f3f;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int vs[1007];
    f (n, i) {
        cin >> vs[i];
    }
    sort (vs, vs+n);
    int ans = n-1;
    int cur = -1, sam = 0;
    int ord[1007], ords = 0;
    f (n, i) {
        if (vs[i] != cur) {
            if (sam > 0) ord[ords++] = sam;
            sam = 0;
        } else {
            sam++;
        }
        cur = vs[i];
    }
    if (sam > 0) ord[ords++] = sam;
    for (int i = 1; i < ords; i++) {
        ord[i] = max (ord[i-1], ord[i]);
    }
    if (ords > 0)
        ans -= ord[ords-1];
    cout << ans << "\n";
}
