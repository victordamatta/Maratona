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
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int cs[5007], inter[5007], ans[5007];
int n;
bool comp1 (pi a, pi b) {
    return a.fst < b.fst;
}

bool comp2 (pi a, pi b) {
    return a.scd < b.scd;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    f (n, i) {
        cin >> cs[i];
    }
    for (int i = 0; i < n; i++) {
        ms (inter, 0);
        int maxv = 0, maxi;
        for (int j = i; j >= 0; j--) {
            inter[cs[j]]++;
            if (inter[cs[j]] > maxv) {
                maxv = inter[cs[j]];
                maxi = cs[j];
            }
            else if (inter[cs[j]] == maxv) {
                if (cs[j] < maxi) {
                    maxi = cs[j];
                }
            }
            ans[maxi]++;
        }
    }
    f(n, i) cout << ans[i+1] << " ";
    cout << endl;
}
