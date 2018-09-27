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

int idex[70007];
int inter[70007];

int seg[300007];
int ans[70007];

void update (int n, int l, int r, int nn, int value) {
    int mid = (l + r)/2;
    if (l == r) {
        seg[n] = value;
        return;
    }
    if (nn <= mid) update (2*n, l, mid, nn, value);
    else update (2*n + 1, mid+1, r, nn, value);

    seg[n] = max (seg[2*n], seg[2*n + 1]);
}

int query (int n, int l, int r, int dl, int dr) {
	if(l>=dl && r<=dr) return seg[n];
	if(dr<l || dl>r) return -1;
	int mid = l + (r-l)/2;
	return max(query(2*n, l, mid, dl, dr), query(2*n+1, mid+1, r, dl, dr));
}

void dfs (int v) {
    idex[v] = ord++;
    for (int u : graph[v]) {
        prof[u] = prof[v] + 1;
        dfs (u);
    }
    inter[v] = ord-1;
}

struct event {
    int type;
    int date;
    int who;

    event (int t, int d, int w) : type(t), date(d), who(w) {
    }
};

bool comp (event a, event b) {
    if (a.date == b.date) {
        return a.type > b.type;
    }
    return a.date < b.date;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) graph[i].clear();
        ms (prof, 0);
        ms (seg, -1);
        for (int i = 1; i <= n; i++) {
            int p;
            cin >> p >> birth[i] >> death[i];
            if (p != -1)
                graph[p+1].pb(i);
        }
        ord = 1;
        dfs (1);

        /*
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (prof[j] == i) cout << idex[j] << " " << "(" << inter[j] << ")" << " ";
            }
            cout << endl;
        }
        cout << endl;
        */

        vector<event> queue;
        for (int i = 1; i <= n; i++) {
            queue.pb (event (1, birth[i], i));
            queue.pb (event (-1, death[i], i));
        }
        sort (queue.begin (), queue.end (), comp);

        /* f(4*n, i) cout << seg[i] << " "; */
        /* cout << endl; */
        for (int i = 0; i < queue.size (); i++) {
            /* cout << queue[i].date << " " << queue[i].type << " " << queue[i].who << endl; */
            int who = queue[i].who;
            if (queue[i].type == -1) {
                ans[who] = query (1, 1, n, idex[who], inter[who]) - prof[who];
            }
            else {
                update (1, 1, n, idex[who], prof[who]);
                /* f(4*n, i) cout << seg[i] << " "; */
                /* cout << endl; */
            }
        }

        cout << ans[1];
        for (int i = 2; i <= n; i++) cout << " " << ans[i];
        cout << endl;
    }
}
