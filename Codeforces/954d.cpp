
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 1004;
const ll MOD = 1000000007;
const int OO = INT_MAX;
inline ll mod(ll x) { return x % MOD; }

vector<int> graph[N];
int n, m;
int s, t;
int ds[N];
int dt[N];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for(int i = 0; i <= n; i++) {
        ds[i] = dt[i] = OO;
    }

    queue<int> q;
    q.push(s);
    ds[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : graph[v]) {
            if(ds[u] == OO) {
                ds[u] = ds[v] + 1;
                q.push(u);
            }
        }
    }

    q.push(t);
    dt[t] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : graph[v]) {
            if(dt[u] == OO) {
                dt[u] = dt[v] + 1;
                q.push(u);
            }
        }
    }

    int pans = 0;
    int dist = ds[t];
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(ds[i] + 1 + dt[j] < dist || dt[i] + 1 + ds[j] < dist) pans++;
        }
    }

    cout << n*(n-1)/2 - pans - m << endl;
}
