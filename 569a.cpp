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
#define f(x, let) for(double let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<double>
#define si set<double>
#define sit set<double>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    double t, s, q;
    cin >> t >> s >> q;
    long long int ans = 0;
    double have, need;
    have = s;
    need = t-s;
    while(need > 0.01){
        ans++;
        while(need > 0.01 && have > 0.001){
            have = (have/q)*(q-1);
            need -= have;
        }
        have = t-need;
    }
    cout << ans << "\n";
}
