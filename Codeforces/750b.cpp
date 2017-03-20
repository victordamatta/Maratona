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

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int alt = 0;
    int ok = true;
    f (n, i) {
        int dis;
        string dir;
        cin >> dis >> dir;
        if (alt == 0) {
            if (dir.compare ("South") != 0) {
                ok = false;
                break;
            }
        }
        else if (alt == 20000) {
            if (dir.compare ("North") != 0) {
                ok = false;
                break;
            }
        }
        if (dir.compare ("South") == 0) {
            if (alt + dis > 20000) {
                ok = false;
                break;
            }
            else {
                alt += dis;
            }
        }
        else if (dir.compare ("North") == 0) {
            if (alt - dis < 0) {
                ok = false;
                break;
            }
            else {
                alt -= dis;
            }
        }
    }
    if (ok && alt == 0) cout << "YES\n";
    else cout << "NO\n";
}
