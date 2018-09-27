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
int lg (int n) {
    if (n == 1) return 0;
    return 1 + lg (n/2);
}

int pw2 (int n) {
    if (n == 0) return 1;
    return 2 * pw2 (n - 1);
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string ar;
        cin >> ar;
        int hi = lg (ar.size ()) + 1;
        int lo = 1;

        while (lo < hi) {
            int mid = (hi + lo) / 2;
            set<string> s;
            string ars = ar.substr (0, mid);
            s.insert (ars);

            for (int i = mid; i < ar.size (); i ++) {
                ars = ars.substr (1, ars.size () - 1);
                ars += ar[i];
                s.insert (ars);
            }

            if (s.size () < pw2 (mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        cout << hi << endl;
    }
}
