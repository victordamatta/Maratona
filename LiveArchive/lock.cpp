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
    int n, t1, t2, t3;
    while (cin >> n >> t1 >> t2 >> t3, n != 0) {
        int ans = 0;
        f (n, i) {
            int cur = 2*n;
            int aux = i - t1;
            if (aux < 0) aux += n;
            cur += aux + n;
            aux = t2 - t1;
            if (aux < 0) aux += n;
            cur += aux;
            aux = t2 - t3;
            if (aux < 0) aux += n;
            cur += aux;

            if (cur > ans) ans = cur;
        }
        cout << ans << endl;
    }
}
