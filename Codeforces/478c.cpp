
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
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define sit set<int>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    ll v[3];
    std::ios::sync_with_stdio(false);
    cin >> v[0] >> v[1] >> v[2];
    sort(v,v+3);
    v[2] = min(v[2],2*(v[0]+v[1]));
    cout << (v[0]+v[1]+v[2])/3 << "\n";
}
