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
typedef pair<int, int> pr;
//REMEMBER TO DECLARE GLOBAL VARIABLES

bool compx(pr a, pr b){
    return a.first < b.first;
}

bool compy(pr a, pr b){
    return a.second < b.second;
}

int main(){
    std::ios::sync_with_stdio(false);
    vector<pair<int, int > > vx;
    vector<pair<int, int > > vy;
    int n;
    cin >> n;
    f(n, i){
        pair<int, int> p;
        int aux1, aux2;
        cin >> aux1 >> aux2;
        p.first = aux1;
        p.second = aux2;
        vx.pb(p);
        vy.pb(p);
    }
    sort(all(vx), compx);
    sort(all(vy), compy);
    int ans;
    f(vx.size(), i){
    }
}
