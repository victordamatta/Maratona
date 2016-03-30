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
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
struct member {
    string name;
    int reg;
    int score;
};

bool comp (member a, member b) {
    return a.score > b.score;
}

int main(){
    std::ios::sync_with_stdio(false);
    member ms[100007];
    int regs[10007];
    pi scs[10007];
    string ans[10007];
    for (int i = 0; i <= 10001; i++) regs[i] = 2;
    int n, m;
    cin >> n >> m;
    f(n, i) {
        string a;
        int x, y;
        cin >> a >> x >> y;
        ms[i].name = a;
        ms[i].reg = x;
        ms[i].score = y;
    }
    sort (ms, ms + n, comp);
    for (int i = 0; i < n; i++) {
        if (regs[ms[i].reg] == 2) {
            ans[ms[i].reg] = ms[i].name;   
            scs[ms[i].reg].fst = ms[i].score;
            regs[ms[i].reg] = 1;
        }
        else if (regs[ms[i].reg] == 1) {
            ans[ms[i].reg] += " " + ms[i].name;   
            scs[ms[i].reg].scd = ms[i].score;
            regs[ms[i].reg] = 0;
        }
        else {
            if (ms[i].score == scs[ms[i].reg].fst || ms[i].score == scs[ms[i].reg].scd) ans[ms[i].reg] = "?";
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
}
