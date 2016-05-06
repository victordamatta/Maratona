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
int n, d, m;
int comp[1000007];
int sz[1000007];
int hs[1000007];
int ds[1000007];
int ans[1000007];

int find (int a) {
    if (comp[a] != a) comp[a] = find (comp[a]);
    return comp[a];
}

void join (int a, int b) {
    int pa = comp[a], pb = comp[b];
    if (pa == pb) return;
    m--;
    if (sz[pa] < sz[pb]) {
        comp[pa] = comp[pb];
    }
    else if (sz[pa] > sz[pb]) {
        comp[pb] = comp[pa];
    }
    else {
        comp[pa] = comp[pb];
        sz[pb]++;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        m = n;
        map<int, vi> htoi;
        f (n, i) {
            comp[i] = i;
            sz[i] = 1;
        }
        f (n, i) {
            cin >> hs[i];
            htoi[hs[i]].pb (i);
        }
        f (d, i) {
            cin >> ds[i];
        }
        for (int i = 1; i < n; i++) {
            if (hs[i-1] > ds[d-1] && hs[i] > ds[d-1]) {
                join (i, i-1);
            }
            if (hs[i+1] > ds[d-1] && hs[i] > ds[d-1]) {
                join (i, i+1);
            }
        }
        ans[d-1] = m;
        for (int i = d-2; i >= 0; i--) {
            //NEVER JOINS ANYTHING - HS[B] = DS[I], IF CHECKS IF >
            /*
            for (int b: htoi[ds[i]]) {
                if (hs[b-1] > ds[i] && hs[b] > ds[i]) {
                    join (b, b-1);
                }
                if (hs[b+1] > ds[i] && hs[b] > ds[i]) {
                    join (b, b+1);
                }
            }
            */
            //Even this is wrong
            f (n, j) {
                if (hs[j-1] > ds[i] && hs[j] > ds[i]) {
                    join (j, j-1);
                }
                if (hs[j+1] > ds[i] && hs[j] > ds[i]) {
                    join (j, j+1);
                }
            }
            ans[i] = m;
        }
        f (d, i) cout << ans[i] << " ";
        cout << endl;
    }
}
