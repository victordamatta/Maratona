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

bool div4 (int x) {
    return x%4 == 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    string a;
    cin >> a;
    ll ans = 0ll;
    ll p = a.size() - 1;
    while (p > 0){
        if(a[p] == '4' || a[p] == '8' || a[p] == '0') ans++;
        if(div4(a[p] - '0' + ((a[p-1] - '0')*10))) ans += p;
        p--;
    }
    if(a[p] == '4' || a[p] == '8' || a[p] == '0') ans++;
    cout << ans << "\n";
}
