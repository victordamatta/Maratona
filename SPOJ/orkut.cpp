//ORDENAÇÃO TOPOLÓGICA
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
vi graph[37];
int n;
map<string, int> code;
map<int, string> decode;
int deg[37];
int main(){
    int t = 1;
    std::ios::sync_with_stdio(false);
    while(cin >> n, n!=0){
        ms(deg, 0);
        f(n, i){
            string a;
            cin >> a;
            code[a] = i+1;
            decode[i+1] = a;
        }
        f(n, i){
            string a;
            int x;
            cin >> a;
            cin >> x;
            f(x, j){
                string b;
                cin >> b;
                graph[code[b]].pb(code[a]);
                deg[code[a]]++;
            }
        }
        vi ans;
        queue<int> q;
        f(n, i){
            if(!deg[i+1]) q.push(i+1);
        }
        while(!q.empty()){
            int aux = q.front();
            q.pop();
            ans.pb(aux);
            f(graph[aux].size(), i){
                if(--deg[graph[aux][i]] == 0) q.push(graph[aux][i]);
            }
        }
        cout << "Teste " << t << "\n";
        if(ans.size() < n) cout << "impossivel\n\n";
        else{
            f(ans.size(), i){
                cout << decode[ans[i]] << " ";
            }
            cout << "\n\n";
        }
        code.clear();
        decode.clear();
        f(n, i) graph[i+1].clear();
        t++;
    }
}
