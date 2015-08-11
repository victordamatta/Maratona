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
    int t, s, q;
    cin >> t >> s >> q;
    long long int ans = 0;
    int have, need;
    have = s;
    need = 0;
    while(have < t){
        have += q-1;
        need += q;
        if(have < t && need >= have){
            ans++;
            need -= have;
        }
    }
    cout << ans+1 << "\n";
}
