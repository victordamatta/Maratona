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

int n, m;
int ints[13];
vector< pair<int, int> > dif[13];

int time(int k, int w){
    if(dif[k][0].first > ints[w]) return OO;
    int i = 0;
    while(i < dif[k].size() && dif[k][i].first <= ints[w]) i++;
    return dif[k][i-1].second;
}

int pd(int k, int f, int s, int t) {
    if(k == n){
        return f + s + t;
    }
    if(m==3) return min(pd(k+1, f+f+time(k, 1), s, t), min(pd(k+1, f, s+s+time(k, 2), t), pd(k+1, f, s, t+t+time(k, 3))));
    else if(m == 2)return min(pd(k+1, f+f+time(k, 1), s, t), pd(k+1, f, s+s+time(k, 2), t)); 
    else return pd(k+1, f+f+time(k, 1), s, t);
}


int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> m >> n, m!=0){
        ms(ints, 0);
        f(13, i) dif[i].clear();
        f(m, i) cin >> ints[i+1];
        f(n, i){
            int k;
            cin >> k;
            f(k, j){
                int a, b;
                cin >> a >> b;
                dif[i].pb(mp(a, b));
            }
        }
        cout << (float) pd(0, 0, 0, 0)/n << "\n";
    }
}
