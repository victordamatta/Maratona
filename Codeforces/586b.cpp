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

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int as[200][5], bs[200];
    as[0][0] = 0;
    f(n-1, i){
        cin >> as[i+1][0];
        as[i+1][0] += as[i][0];
    }
    as[0][1] = 0;
    f(n-1, i){
        cin >> as[i+1][1];
        as[i+1][1] += as[i][1];
    }
    f(n, i)
        cin >> bs[i];

    int ans = INT_MAX, c;
    for(int i = n-1; i >= 0; i--) {
        int aux;
        aux = bs[i];
        aux += as[n-1][1] - as[i][1];
        aux += as[i][0];
        if (aux < ans) {
            ans = aux;
            c = i;
        }
    }
    int ans2 = INT_MAX;
    for(int i = n-1; i >= 0; i--) {
        int aux;
        if (i == c) continue;
        aux = bs[i];
        aux += as[i][0];
        aux += as[n-1][1] - as[i][1];
        if (aux < ans2) {
            ans2 = aux;
        }
    }
    cout << ans + ans2 << "\n";
}
