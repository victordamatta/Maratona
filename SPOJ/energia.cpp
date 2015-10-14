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
int e, l;
vi graph[200];
int ok[200];

void dfs(int node){
    if(ok[node]) return;
    ok[node] = 1;
    for(int i = 0; i < graph[node].size(); i++){
        dfs(graph[node][i]);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int test = 1;
    while(cin >> e >> l, e != 0){
        ms(ok, 0);
        f(l, i){
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1);
        cout << "Teste " << test << "\n";
        int aux = 1;
        f(e, i){
            if(!ok[i+1]){
                cout << "falha\n";
                aux = 0;
                break;
            }
        }
        if(aux)
            cout << "normal\n";
        cout << "\n";
        test++;
        f(e+1, i){
            graph[i].clear();
        }
    }
}
