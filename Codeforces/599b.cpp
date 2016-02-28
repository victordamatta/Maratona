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

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    int qs[100007], amb = 0, imp = 0;
    int ma[100007], bs[100007];
    ms(ma, 0);
    ms(qs, 0);
    ms(bs, 0);
    cin >> n >> m;
    f(n, i) {
        int x;
        cin >> x;
        qs[x]++;
        if(qs[x] > 1) amb = 1;
        ma[x] = i;
    }
    f(m, i){
        int x;
        cin >> x;
        bs[i] = x;
        if(qs[x] == 0) imp = 1;
    }
    if (imp) cout << "Impossible\n";
    else if (amb) cout << "Ambiguity\n";
    else {
        cout << "Possible\n";
        f(m, i){
            cout << ma[bs[i]] + 1 << " ";
        }
        cout << "\n";
    }
}
