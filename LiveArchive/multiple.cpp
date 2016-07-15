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
//REMEMBER LONG LONG ll
//REMEMBER TO INITIALZE THINGS
ll digits[10];
ll digi;

void mark (ll x) {
    while (x > 0) {
        ll aux = x % 10;
        if (digits[aux] == 0) {
            digi--;
            digits[aux]++;
        }
        x /= 10;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    while (cin >> n) {
        ms (digits, 0);
        ll k = 1;
        digi = 10;
        while (digi > 0) {
            mark (k*n);
            k++;
        }
        cout << k - 1 << endl;
    }
}
