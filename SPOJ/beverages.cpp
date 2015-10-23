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
vi graph[107];
int degree[107];
map<string, int> code;
vector<string> decode;
int n, m;

int main(){
    std::ios::sync_with_stdio(false);
    int t = 1;
    while(cin >> n){
        ms(degree, 0);

        f(n, i){
            string a;
            cin >> a;
            code[a] = i;
            decode.pb(a);
        }
        cin >> m;
        f(m, i){
            string a, b;
            cin >> a >> b;
            graph[code[a]].pb(code[b]);
            degree[code[b]]++;
        }

        vi ans;
        si s;
        f(n, i){
            if(!degree[i]) s.insert(i);
        }
        while(!s.empty()){
            int aux = *s.begin();
            ans.pb(aux);
            f(graph[aux].size(), j){
                if(--degree[graph[aux][j]] == 0) s.insert(graph[aux][j]);
            }
            s.erase(aux);
        }

        cout << "Case #" << t << ": Dilbert should drink beverages in this order: ";
        f(ans.size()-1, i){
            cout << decode[ans[i]] << " ";
        }
        cout << decode[ans[ans.size()-1]] << ".\n\n";

        code.clear();
        decode.clear();
        f(n, i) graph[i].clear();

        t++;
    }
}
