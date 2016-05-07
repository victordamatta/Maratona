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
    int n, m;
    cin >> n >> m;
    vi div1;
    vi div2;
    f (m, i) {
        int aux, aux2;
        cin >> aux >> aux2;
        div1.pb (-max (aux, aux2));
        div2.pb (min (aux, aux2));
    }
    if (m > 0) {
        make_heap (div1.begin (), div1.end ());
        make_heap (div2.begin (), div2.end ());
        if (div2[0] >= -div1[0]) {
            cout << 0 << endl;
            return 0;
        }
        int used = 0;
        for (int i = 1; i <= n; i++) {
            if (i <= div2[0]) used++;
            else if (-i <= div1[0]) used++;
        }
        int ava = n - used;
        cout << ava+1 << endl;
    }
    else {
        cout << n-1 << endl;
    }
    return 0;
}
