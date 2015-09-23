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
#define aint(x) x.begin(), x.end()
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
//REMEMBER TO DECLARE GLOBAL VARIABLES

int bit[10007];
int t, n, u, l, r, q, aux;

int query (int k) {
    int sum = 0;
    for (int i = k; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update (int k, int val) {
    for (int i = k; i <= n; i+= i&-i)
        bit[i] += val;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ms (bit, 0);
        cin >> n >> u;
        while (u--) {
            cin >> l >> r >> aux;
            l++;
            r++;
            update (l, aux);
            update (r + 1, -aux);
        }
        cin >> q;
        while (q--) {
            cin >> aux;
            aux++;
            cout << query (aux) << "\n";
        }
    }
}
