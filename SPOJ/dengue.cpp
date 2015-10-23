
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
vi graph[107];
int dis[107], mdis[107];
int n;

int main(){
    std::ios::sync_with_stdio(false);
    int t = 1;
    while(cin >> n, n != 0){
        ms(mdis, 0);
        f(n-1, i){
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        int maxi;
        f(n, i){
            ms(dis, 0);
            maxi = 0;
            queue<int> bfs;
            bfs.push(i+1);
            dis[i+1] = 0;
            while(!bfs.empty()){
                int aux = bfs.front();
                maxi = max(maxi, dis[aux]);
                bfs.pop();
                f(graph[aux].size(), j){
                    if(!dis[graph[aux][j]] && graph[aux][j] != i+1){
                        dis[graph[aux][j]] = dis[aux] + 1;
                        bfs.push(graph[aux][j]);
                    }
                }
            }
            mdis[i+1] = maxi;
        }
        int a = INT_MAX, ans;
        f(n, i){
            if(mdis[i+1] < a){
                a = mdis[i+1];
                ans = i+1;
            }
        }
        cout << "Teste " << t << "\n";
        t++;
        cout << ans << "\n\n";
        f(n, i) graph[i+1].clear();
    }
}
