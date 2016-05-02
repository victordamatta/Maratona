//CHECAR CASO a = b = 1
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
int fa[1000007], fb[1000007];
int crivo[1000007];

int main(){
    std::ios::sync_with_stdio(false);
    int a, b;
    int t = 1;
    f(1000007, i) crivo[i] = i;
    for (int i = 2; i <1000007; i++) {
        if (crivo[i] != i) continue;
        for (int j = i*i; j < 1000007; j += i) {
            crivo[j] = j;
        }
    }
    while (cin >> a >> b, a != 0) {
        ms (fa, 0);
        ms (fb, 0);
        set<int> s;
        while (a > 1) {
            s.insert (crivo[a]);
            fa[crivo[a]]++;
            a /= crivo[a];
        }
        while (b > 1) {
            s.insert (crivo[b]);
            fb[crivo[b]]++;
            b /= crivo[b];
        }
        int dif = 0;
        for (int i = 0; i < 1000005; i++) {
            dif += abs (fa[i] - fb[i]);
        }
        cout << t << ". " << s.size () << ":" << dif << endl;
        t++;
    }
}
