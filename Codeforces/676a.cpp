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
    int ar[107];
    f (n, i) cin >> ar[i];
    int pos1, pos2;
    f (n, i) {
        if (ar[i] == 1) pos1 = i;
        if (ar[i] == n) pos2 = i;
    }
    if (pos1 > pos2) swap (pos1, pos2);
    cout << max (pos2, n - pos1 - 1) << endl;
}
