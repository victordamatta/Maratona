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
vi audio;
vi sub;
map<int, int> bylang;
int n, m;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    f (n, i) {
        int aux;
        cin >> aux;
        if (bylang.find (aux) == bylang.end ()) {
            bylang[aux] = 1;
        }
        else {
            bylang[aux] = bylang[aux] + 1;
        }
    }
    cin >> m;
    f (m, i) {
        int aux;
        cin >> aux;
        audio.pb (aux);
        if (bylang.find (aux) == bylang.end ()) {
            bylang[aux] = 0;
        }
    }
    f (m, i) {
        int aux;
        cin >> aux;
        sub.pb (aux);
        if (bylang.find (aux) == bylang.end ()) {
            bylang[aux] = 0;
        }
    }
    int bs = 0, cs = 0, ans = 0;
    f (m, i) {
        if (bylang[audio[i]] > bs) {
            bs = bylang[audio[i]];
            cs = bylang[sub[i]];
            ans = i;
        }
        else if (bylang[audio[i]] == bs) {
            if (bylang[sub[i]] > cs) {
                bs = bylang[audio[i]];
                cs = bylang[sub[i]];
                ans = i;
            }
        }
    }
    cout << ans+1 << endl;
}
