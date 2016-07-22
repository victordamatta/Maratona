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
int good[] = {1, 2, 3, 3, 4, 10};
int evil[] = {1, 2, 2, 2, 3, 5, 10};

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    f (t, k) {
        ll gf = 0, ef = 0;
        f (6, i) {
            ll aux;
            cin >> aux;
            gf += aux * good[i];
        }
        f (7, i) {
            ll aux;
            cin >> aux;
            ef += aux * evil[i];
        }

        cout << "Battle " << k+1 << ": ";
        if (gf > ef) cout << "Good triumphs over Evil";
        else if (ef > gf) cout << "Evil eradicates all trace of Good";
        else cout << "No victor on this battle field";
        cout << endl;
    }
}
