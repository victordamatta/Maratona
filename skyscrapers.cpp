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
struct build {
    int h;
    int i;
}

int n, d, m;
int comp[1000007];
int sz[1000007];
int ds[1000007];
int ans[1000007];
build bs[1000007];
bool comp (build a, build b) {
    return a.h < b.h;
}

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
        int x = n;
        f (n, i) {
            comp[i] = i;
            sz[i] = 1;
        }
        f (n, i) {
            int aux;
            cin >> aux;
            bs[i].h = aux;
            bs[i].i = i;
        }
        sort (bs, bs+n, comp);
        f (d, i) {
            cin >> ds[i];
        }
        for (int i = n-1; i >= 0; i--) {
            if (bs[i-1].h > ds[d-1] && bs[i].h > ds[d-1]) {
                join (i, i-1);
            }
            if (bs[i+1].h > ds[d-1] && bs[i].h > ds[d-1]) {
                join (i, i+1);
            }
        }
        ans[d-1] = m;
        for (int i = d-2; i >= 0; i--) {
            ans[i] = m;
        }
        f (d, i) cout << ans[i] << " ";
        cout << endl;
    }
}
