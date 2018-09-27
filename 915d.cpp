
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)
#define int long long
using namespace std;
typedef pair<int, int> pi;
///////////////0123456789
const int  N = 10004;
const int MOD = 1000000007;
const int OO = INT_MAX;
inline int mod(int x) { return x % MOD; }

vector<int> graph[507];
int n, m;
vector<int> seen;
vector<int> st;
vector<int> disc;
vector<int> low;
int tempo;

void tarjan(int v, pi forbid, vector<pi>& cc) {
    /* cout << v << endl; */
    seen[v] = 1;
    st.push_back(v);
    disc[v] = low[v] = tempo++;
    for(int adj : graph[v]) {
        if(v == forbid.fst && adj == forbid.snd) continue;
        if(!seen[adj]) tarjan(adj, forbid, cc);
        low[v] = min(low[v], low[adj]);
    }
    if(cc.size() > 1) return;
    if(disc[v] == low[v]) {
        /* cout << endl; */
        /* for(int i = 0; i < n; i++) cout << disc[i] << " " << low[i] << endl; */
        /* cout << endl; */

        int prev = v;
        while(st.back() != v) {
            low[st.back()] = OO;
            cc.pb(mp(st.back(), prev));
            prev = st.back();
            st.pop_back();
        }
        cc.pb(mp(v, prev));
        st.pop_back();
    }
    if(cc.size() == 1) cc.clear();
    low[v] = OO;
}

int32_t main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].pb(b-1);
    }

    tempo = 0;
    seen = vector<int>(n, 0);
    disc = vector<int>(n, -1);
    low = vector<int>(n, INT_MAX);

    vector<pi> cc;
    for(int i = 0; i < n; i++) {
        tarjan(i, mp(-1, -1), cc);
    }

    if(cc.size() <= 1) {
        /* cout << "BUGBUGAGA" << endl; */
        goto success;
    }

    for(auto e : cc) {
        tempo = 0;
        seen = vector<int>(n, 0);
        disc = vector<int>(n);
        low = vector<int>(n);
        st.clear();
        vector<pi> det;
        for(int i = 0; i < n; i++) tarjan(i, e, det);
        if(det.size() <= 1) {
            //cout << e.fst << " " << e.snd << endl;
            goto success;
        }
    }

failure:
    cout << "NO" << endl;
    return 0;
success:
    cout << "YES" << endl;
}
