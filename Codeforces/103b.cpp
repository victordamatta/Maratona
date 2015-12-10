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
int n, m;
int p[107];
int size[107];
int cycles, maxi;

int find(int v){
    if(p[p[v]] != p[v]) p[v] = find(p[v]); 
    return p[v];
}

void join(int a, int b){
    if(a == b){
        cycles++;
        return;
    }
    if(size[b] > size[a]) swap(a, b);
    p[b] = a;
    size[a] += size[b];
    maxi = max(maxi, size[a]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    f(n, i){
        p[i+1] = i+1;
        size[i+1] = 1;
    }
    cycles = maxi = 0;
    f(m, i){
        int a, b;
        cin >> a >> b;
        join(find(a), find(b));
    }
    if(cycles == 1 && maxi == n) cout << "FHTAGN!\n";
    else cout << "NO\n";
}
