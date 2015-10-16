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
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define sit set<int>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int graph[5007][5007];
int help[5007];
int v, e;

void search(int s, int c){
    if(help[c]) return;
    help[c] = 1;
    for(int i = 1; i <= v; i++){
        if(help[i]) continue;
        if(graph[c][i]){
            graph[s][i] = 1;
            search(s, i);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> v, v!=0){
        ms(graph, 0);
        cin >> e;
        f(e, i){
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
        }
        f(v, i){
            ms(help, 0);
            help[i+1] = 1;
            f(v, j){
                if(graph[i+1][j+1]){
                    search(i+1, j+1);
                }
            }
        }
        vi ans;
        int ok;
        f(v, i){
            ok = 1;
            f(v, j){
                if(graph[i+1][j+1] && !graph[j+1][i+1]){
                    ok = 0;
                    break;
                }
            }
            if(ok) ans.pb(i+1);
        }
        f(ans.size(), i){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
