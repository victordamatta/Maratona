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

int n, bit[10000007], in[1000000];

int query (int k) {
    int sum = 0;
    for (int i = k; i>0; i-=i&-i) {
        sum += bit[i];
    }
    return sum;
}

void update (int k) {
    for (int i = k; i <= n; i += i&-i) {
        bit[i]++;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ms (bit, 0);
        int aux, maxi = 0;
        cin >> n;
        f(n, i) {
            cin >> in[i];
            maxi = max(maxi, in[i]);
            update (in[i]);
        }
        int ans = 0;
        for (int i = n - 1; i>=0; i--) {
            ans += query (maxi) - query (in[i]);
        }
        cout << ans << "\n";
    }
}
