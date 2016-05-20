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
struct build {
    int h;
    int i;
};

int n, d, m;
int ds[1000007];
int ans[1000007];
build bs[1000007];
bool cmp (build a, build b) {
    return a.h < b.h;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        f (n, i) {
            int aux;
            cin >> aux;
            bs[i].h = aux;
            bs[i].i = i;
        }
        sort (bs, bs+n, cmp);
        f (d, i) {
            cin >> ds[i];
        }
        int i = n - 1;
        int ansi = 0;
        set<int> s;
        for (int j = d-1; j >= 0; j--) {
            while (bs[i].h > ds[j]) {
                if (s.find (bs[i].i + 1) == s.end () && s.find (bs[i].i - 1) == s.end()) {
                    ansi++;
                }
                else if (s.find (bs[i].i + 1) != s.end () && s.find (bs[i].i - 1) != s.end()) {
                    ansi--;
                }
                s.insert (bs[i].i);
                i--;
            }
            ans[j] = ansi;
        }
        cout << ans[0];
        f (d-1, i) cout << " " << ans[i+1];
        cout << endl;
    }
}
