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
    int n;
    cin >> n;
    int c, d;
    vpi cont;
    f (n, i) {
        cin >> c >> d;
        cont.pb (mp (c, d));
    }

    int ok = true;
    f (n, i) {
        if (cont[i].scd != 1) ok = false;
    }
    if (ok) {
        cout << "Infinity\n";
        return 0;
    }
    int maxi = OO, mini = -OO;
    int acc = 0;
    f (n, i) {
        if (cont[i].scd == 1) {
            mini = max (mini, 1900 - acc);
        }
        else {
            maxi = min (maxi, 1899 - acc);
        }
        acc += cont[i].fst;
    }
    if (mini > maxi) cout << "Impossible\n";
    else cout << maxi + acc << "\n";
}
