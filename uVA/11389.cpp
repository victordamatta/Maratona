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

int main(){
    std::ios::sync_with_stdio(false);
    int n, d, r;
    while(cin >> n >> d >> r, n != 0){
        vi haves;
        f(n, i){
            int aux;
            cin >> aux;
            haves.pb(d-aux);
        }
        sort(all(haves));
        int k = haves.size() - 1;
        int ans = 0;
        vi wants;
        f(n, i){
            int aux;
            cin >> aux;
            wants.pb(aux);
        }
        sort(all(wants));
        f(n, i){
            ans += max(wants[i]-haves[i], 0);
        }
        cout << ans * r << "\n";
    }
}
