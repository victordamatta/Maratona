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
map<string, int> m;
vi graph[107];
int ds[107];
int a;

bool ord(string x, string y){
    string i, j;
    i = x.substr(2);
    j = y.substr(2);
    if(i < j) return true;
    else if(i > j) return false;
    else return x[0] < y[0];
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> a, a != 0){
        int n = 1;
        vector<string> ans;
        ms(ds, 0);
        f(a, i){
            //INPUT WRONG
            string x="";
            vector<string> authors;
            char c = 'a';
            while(cin >> c, c != '.'){
                if(c == ','){
                    authors.pb(x);
                    if(m.find(x) == m.end()){
                        m[x] = n++;
                        ans.pb(x);
                    }
                    cout << x << "\n";
                    x = "";
                    cin >> c;
                }
                else
                    x += c;
            }
            authors.pb(x);
            if(m.find(x) == m.end()){
                m[x] = n++;
                ans.pb(x);
            }
            f(authors.size(), g){
                f(authors.size(), h){
                    if(h == g) continue;
                    graph[m[authors[g]]].pb(m[authors[h]]);
                }
            }
        }
        queue<int> q;
        q.push(m["P. Erdos"]);
        while(!q.empty()){
            int aux = q.front();
            q.pop();
            f(graph[aux].size(), i){
                if(!ds[graph[aux][i]]){
                    ds[graph[aux][i]] = ds[aux]+1;
                    q.push(graph[aux][i]);
                }
            }
        }
        sort(all(ans), ord);
        f(ans.size(), i){
            if(ans[i] == "P. Erdos") continue;
            int aux = ds[m[ans[i]]];
            if(aux)
                cout << ans[i] << ": " << aux << "\n";
            else
                cout << ans[i] << ": infinito\n";
        }
        f(n-1, i){
            graph[i+1].clear();
        }
    }
}
