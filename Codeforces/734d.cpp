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
const int OO = 2000000001;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int n;
pi k;
int p[500007];
pi pl[500007];

int bi[] = {1, 1, -1, -1};
int bj[] = {-1, 1, 1, -1};
int ri[] = {0, 1, 0, -1};
int rj[] = {-1, 0, 1, 0};

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> k.fst >> k.scd;
    f (n, i) {
        char c;
        cin >> c >> pl[i].fst >> pl[i].scd;
        if (c == 'B') p[i] = 0;
        else if (c == 'R') p[i] = 1;
        else p[i] = 2;
    }

    bool ans = false;
    for (int t = 0; t < 4; t++) {
        int dis = OO;
        int mint = 3;
        for (int x = 0; x < n; x++) {
            pi delta;
            delta.fst = k.fst - pl[x].fst;
            delta.scd = k.scd - pl[x].scd;
            if (delta.fst * bj[t] - delta.scd * bi[t] == 0) {
                int td = max (abs (delta.fst), abs (delta.scd));
                if (delta.fst != 0) delta.fst /= abs (delta.fst);
                if (delta.scd != 0) delta.scd /= abs (delta.scd);
                if (delta.fst == bi[t] && delta.scd == bj[t]) {
                    if (td < dis) {
                        dis = td;
                        mint = p[x];
                    }
                }
            }
        }

        if (mint == 0 || mint == 2) ans = true;
    }
    for (int t = 0; t < 4; t++) {
        int dis = OO;
        int mint = 3;
        for (int x = 0; x < n; x++) {
            pi delta;
            delta.fst = k.fst - pl[x].fst;
            delta.scd = k.scd - pl[x].scd;
            if (delta.fst * rj[t] - delta.scd * ri[t] == 0) {
                int td = max (abs (delta.fst), abs (delta.scd));
                if (delta.fst != 0) delta.fst /= abs (delta.fst);
                if (delta.scd != 0) delta.scd /= abs (delta.scd);
                if (delta.fst == ri[t] && delta.scd == rj[t]) {
                    if (td < dis) {
                        dis = td;
                        mint = p[x];
                    }
                }
            }
        }

        if (mint == 1 || mint == 2) ans = true;
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
