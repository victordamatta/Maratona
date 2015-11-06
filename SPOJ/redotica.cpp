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
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 0x3f3f3f;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
struct edge {
    int x;
    int y;
    int w;
};

vector<edge> v;
int p[107];
int n, m;

int find(int u){
    if(p[p[u]] != p[u]) p[u] = find(p[u]);
    return p[u];
}

void join(int a, int b){
    if(a == b) return;
    p[b] = a;
}

bool comp(edge a, edge b){
    return a.w < b.w;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t = 1;
    while(cin >> n >> m, n != 0){
        f(m, i){
            int a, b, c;
            cin >> a >> b >> c;
            if(a > b) swap(a, b);
            edge e;
            e.x = a;
            e.y = b;
            e.w = c;
            v.pb(e);
        }
        f(n, i){
            p[i+1] = i+1;
        }
        sort(all(v), comp);
        cout << "Teste " << t << "\n";
        f(v.size(), i){
            edge e = v[i];
            if(find(e.x) != find(e.y)){
                cout << e.x << " " << e.y << "\n";
                join(find(e.x), find(e.y));
            }
        }
        t++;
        v.clear();
    }
}
