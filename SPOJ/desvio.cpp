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
#define all(x) x.begin(), x.end()
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
const int OO = 0x3f3f3f;
//REMEMBER TO DECLARE GLOBAL VARIABLES
//REMEMBER LONG LONG INT
int n, m, c, k;
vpi graph[257];
int vis[257];
int dis[257];

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> n >> m >> c >> k, n != 0){
        ms(vis, 0);
        f(n, i){
          dis[i] = INT_MAX;
        }
        f(m, i){
            int x, y, z;
            cin >> x >> y >> z;
            graph[x].pb(mp(-z, y));
            graph[y].pb(mp(-z, x));
        }
        priority_queue<pi> q;
        q.push(mp(0, k));
        dis[k] = 0;
        while(!q.empty()){
            pi aux = q.top();
            q.pop();
            if(vis[aux.scd]) continue;
            vis[aux.scd] = 1;
            int cur = aux.scd;
            if(cur == c-1) break;
            f(graph[cur].size(), i){
                int nowi = graph[cur][i].scd;
                if(cur < c && nowi != cur+1)
                    continue;
                if(!vis[nowi]) q.push(mp(-dis[cur]+graph[cur][i].fst, nowi));
                if(dis[nowi] > dis[cur]-graph[cur][i].fst)
                    dis[nowi] = dis[cur]-graph[cur][i].fst;
            }
        }
        cout << dis[c-1] << "\n";
        f(n, i) graph[i].clear();
    }
}
