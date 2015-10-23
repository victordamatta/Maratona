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
int degree[107];
int n;

int main(){
    std::ios::sync_with_stdio(false);
    int t = 1;
    while(cin >> n, n != 0){
        ms(degree, 0);
        f(n-1, i){
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            degree[b]++;
            graph[b].pb(a);
            degree[a]++;
        }
        queue<int> q;
        f(n, i){
            if(degree[i+1] == 1) q.push(i+1);
        }
        int ans = 1;
        while(!q.empty()){
            int aux = q.front();
            ans = aux;
            q.pop();
            f(graph[aux].size(), i){
                if(--degree[graph[aux][i]] == 1) q.push(graph[aux][i]);
            }
        }
        cout << "Teste " << t << "\n";
        t++;
        cout << ans << "\n\n";
        f(n, i) graph[i+1].clear();
    }
}
