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

int dfs(int v){
    int mini = INT_MAX;
    if(visited[v]) return mini;
    f(graph[v].size(), i){
        mini = min(min(mini, age[graph[v][i]]), dfs(graph[v][i]));
    }
    return mini;
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

                graph[b].swap(graph[a]);

                f(n, x){
                    f(graph[x+1].size(), y){
                        if(graph[x+1][y] == a) graph[x+1][y] = b;
                        if(graph[x+1][y] == b) graph[x+1][y] = a;
                    }
                }
            }
            else{
                cin >> a;
                ms(visited, 0);
                b = dfs(a);
                if(b == INT_MAX)
                    cout << "*\n";
                else
                    cout << b << "\n";
            }
        }
        f(n, i) graph[i+1].clear();
    }
}
