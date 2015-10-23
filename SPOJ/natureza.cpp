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
map<string, int> code;
int c, r;
int p[5007], size[5007];
int maxi = 0;

int find(int v){
    if(p[p[v]] != p[v]) p[v] = find(p[v]);
    return p[v];
}

void join(int a, int b){
    if(a == b) return;
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    p[b] = a;
    maxi = max(maxi, size[a]);
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> c >> r, c != 0){
        maxi = 1;
        int n = 1;
        f(c, i){
            string a;
            cin >> a;
            code[a] = n++;
        }
        f(n, i){
            p[i+1] = i+1;
            size[i+1] = 1;
        }
        f(r, i){
            string a, b;
            cin >> a >> b;
            join(find(code[a]), find(code[b]));
        }
        cout << maxi << "\n";
        code.clear();
    }
}
