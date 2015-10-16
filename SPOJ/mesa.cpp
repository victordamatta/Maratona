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
int sides[107];
int n, m;

int main(){
    std::ios::sync_with_stdio(false);
    int t = 1;
    while(cin >> n){
        ms(sides, 0);
        cin >> m;
        int a, b;
        f(m, i){
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        queue<int> q;
        int ok = 1;
        f(n, j){
            if(sides[j+1] != 0) continue;
            q.push(j+1);
            sides[j+1] = 1;
            while(!q.empty()){
                int aux = q.front();
                q.pop();
                f(graph[aux].size(), i){
                    if(sides[graph[aux][i]] == 0){
                        q.push(graph[aux][i]);
                        sides[graph[aux][i]] = -sides[aux];
                    }
                    else if(sides[graph[aux][i]] == sides[aux]){
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok == 0) break;
        }
        cout << "Instancia " << t << "\n";
        if(ok) cout << "sim\n\n";
        else cout << "nao\n\n";
        t++;
        f(n, i){
            graph[i+1].clear();
        }
    }
}
