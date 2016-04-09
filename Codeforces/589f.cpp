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
    int n, need[107];
    pi inter [107];
    cin >> n;
    f(n, i) {
        int a, b;
        cin >> a >> b;
        inter[i] = mp (a, b);
    }
    int i = 0, f = 10000, m;
    m = (i + f) / 2;
    while (i < f) {
        ms (need, 0);
        for (int x = 0; x < 10000; x++) {
            int mini = INT_MAX, minii = n + 1;
            for (int y = 0; y < n; y++) {
                if (inter[y].fst <= x) {
                    if (inter[y].scd > x) {
                        if (need[y] < m) {
                            if (inter[y].scd < mini) {
                                mini = inter[y].scd;
                                minii = y;
                            }
                        }
                    }
                }
            }
            need[minii]++;
        }
        int b = true;
        for (int x = 0; x < n && b; x++) {
            if (need[x] != m) b = false;
        }
        if (b) {
            if (i == m) {
                i = m;
                m = (i + f) / 2 + 1;
            }
            else {
                i = m;
                m = (i + f) / 2;
            }
        }
        else {
            f = m - 1;
            m = (i + f) / 2;
        }
    }
    cout << n * i << "\n";
}
