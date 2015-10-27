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
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 0x3f3f3f;
//REMEMBER TO DECLARE GLOBAL VARIABLES
vector<pair<int, int> > graph[107];
int n, m, s, d;
int dist[107], vis[107];
int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> n >> m, n != 0){
        f(n, i){
            dist[i+1] = OO;
        }
        ms(vis, 0);
        f(m, i){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].pb(mp(-c, b));
        }
        cin >> s >> d;
        priority_queue<pair<int, int> > q;
        q.push(mp(0, s));
        dist[s] = 0;
        int fail = 1;
        while(!q.empty()){
            pi aux = q.top();
            q.pop();
            int cur = aux.scd;
            if(vis[cur]) continue;
            vis[cur] = 1;
            if(cur == d){
                cout << dist[aux.scd] << "\n";
                fail = 0;
                break;
            }
            f(graph[cur].size(), i){
                int newi = graph[cur][i].scd; 
                if(!vis[newi])
                    q.push(mp(-dist[cur] + graph[cur][i].fst, newi));
                if(dist[cur] - graph[cur][i].fst < dist[newi]){
                    dist[newi] = dist[cur] - graph[cur][i].fst;
                }
            }
        }
        if(fail) cout << "-1\n";
        f(n, i) graph[i+1].clear();
    }
}
