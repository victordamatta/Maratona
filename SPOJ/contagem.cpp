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
string a;
ll ans;
bool ispre(string x, string y){
    if(x.length() > y.length()) return 0;
    for(int i = 0; i<x.length(); i++){
        if(x[i] != y[i]) return 0;
    }
    return 1;
}
void formword(string x, int node, ll val){
    if(x == a && node){
        ans += val;
        return;
    }
    else if(!ispre(x, a)) return;
    if(node == 0){
        formword(x + 'b', 0, val);
        formword(x + 'a', 0, val);
        formword(x + 'b', 1, val);
    }
    else{
        formword(x + 'b', 1, 2*val);
        formword(x + 'a', 1, 2*val);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int t = 1;
    while(cin >> a){
        ans = 0ll;
        formword("", 0, 1ll);
        cout << "Palavra " << t << "\n";
        cout << ans << "\n";
        cout << "\n";
        t++;
    }
}
