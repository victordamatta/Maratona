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
typedef unsigned char uch;
uch tr[300], in[200007];

int main(){
    std::ios::sync_with_stdio(false);
    for(unsigned char c = 'a'; c <= 'z'; c++){
        tr[c] = c;
    }
    int n, m;
    cin >> n >> m;
    f(n, i){
        cin >> in[i];
    }
    f(m, i){
        unsigned char a, b, c;
        cin >> a >> b;
        c = tr[a];
        tr[a] = tr[b];
        tr[b] = c;
    }
    uch tr2[300];
    for(unsigned char c = 'a'; c <= 'z'; c++){
        tr2[tr[c]] = c;
    }
    f(n, i){
        cout << tr2[in[i]];
    }
    cout << "\n";
}
