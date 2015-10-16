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
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 0x3f3f3f;
//REMEMBER TO DECLARE GLOBAL VARIABLES
ll n, aux, pws[10000000];
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    f(n,i){
        cin >> aux;
        pws[aux]++;
    }
    ll ans = 0, carry = 0;
    f(1000001, i){
        carry += pws[i];
        if(carry%2 == 1){
            ans++;
            carry--;
        }
        carry /= 2;
    }
    while(carry){
        if(carry%2 == 1){
            ans++;
            carry--;
        }
        carry /= 2;
    }
    cout << ans << "\n";
}
