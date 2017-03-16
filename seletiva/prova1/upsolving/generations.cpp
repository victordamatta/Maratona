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
int n, ord;
vi graph[70007];
int prof[70007];

int birth[70007];
int death[70007];

int index[70007];
int inter[70007];

int seg[140007];

void update (int n, int l, int r, int nn) {
    int mid = (l + r)/2;
    if (l == r) {
        seg[n] = prof[n];
        return;
    }
    if (nn <= mid) update (2*n, l, mid, nn);
    else update (2*n + 1, mid+1, r, nn);

    seg[n] = max (seg[2*n], seg[2*n + 1]);
}

void query (int n, int l, int r, int dl, int dr) {
	if(l>=dl && r<=dr) return seg[n];
	if(r<ini || l>fim) return INT_MAX;
	int mid = ini + (fim-ini)/2;
	return min(tmin(2*node, ini, mid, l, r), tmin(2*node+1, mid+1, fim, l, r));
}

void dfs (int v) {
    index[v] = ord++;
    for (int u : graph[v]) {
        prof[u] = prof[v+1];
        dfs (u);
    }
    inter[v] = ord;
}

struct event {
    int type;
    int date;
    int who;

    event (int type, int date, int who) : type(type), date(date), who(who) {
    }
}

bool comp (event a, event b) {
    return a.date < b.date;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ms (prof, 0);
        ms (seg, -1);
        for (int i = 1; i <= n; i++) {
            int p;
            cin >> p >> birth[i] >> death[i];
            if (p != -1)
                graph[p].pb(i);
        }
        ord = 0;
        dfs (0);

        vector<event> queue;
        for (int i = 1; i <= n; i++) {
            queue.pb (event (1, birth[i], i));
            queue.pb (event (-1, death[i], i));
        }
        sort (queue.begin (), queue.end (), comp);
    }
}
