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
vi graph[507];
int n, m, k;
int age[507];
int visited[507];
int mini;

void dfs(int v, int org){
    if(visited[v]) return;
    visited[v] = 1;
    if(v != org)
        mini = min(mini, age[v]);
    f(graph[v].size(), i){
        dfs(graph[v][i], org);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> n >> m >> k){
        ms(age, 0);
        f(n, i){
            cin >> age[i+1];
        }
        f(m, i){
            int a, b;
            cin >> a >> b;
            graph[b].pb(a);
        }
        f(k, i){
            char c;
            int a, b;
            cin >> c; 
            if(c == 'T'){
                cin >> a >> b;
                graph[a].swap(graph[b]);
                f(n, x){
                    f(graph[x+1].size(), j){
                        if(graph[x+1][j] == a) graph[x+1][j] = b;
                        else if(graph[x+1][j] == b) graph[x+1][j] = a;
                    }
                }
            }
            else{
                cin >> a;
                ms(visited, 0);
                mini = INT_MAX;
                dfs(a, a);
                if(mini == INT_MAX)
                    cout << "*\n";
                else
                    cout << mini << "\n";
            }
        }
        f(n, i) graph[i+1].clear();
    }
}
