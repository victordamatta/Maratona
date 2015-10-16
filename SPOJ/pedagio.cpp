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
vi graph[57];
int ds[57];
int c, e, l, p;
int main(){
    std::ios::sync_with_stdio(false);
    int t = 1;
    while(cin >> c >> e >> l >> p, c != 0){
        ms(ds, 0);
        f(e, i){
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        queue<int> q;
        vi ans;
        q.push(l);
        ds[l] = 0;
        while(!q.empty()){
            int aux = q.front();
            q.pop();
            if(ds[aux] > p) break;
            f(graph[aux].size(), i){
                if(!ds[graph[aux][i]] && graph[aux][i] != l){
                    ds[graph[aux][i]] = ds[aux] + 1;
                    q.push(graph[aux][i]);
                    if(ds[aux] + 1 <= p) ans.pb(graph[aux][i]);
                }
            }
        }
        cout << "Teste " << t << "\n";
        sort(all(ans));
        f(ans.size(), i){
            cout << ans[i] << " ";
        }
        cout << "\n";
        t++;
        f(c, i){
            graph[i+1].clear();
        }
    }
}
