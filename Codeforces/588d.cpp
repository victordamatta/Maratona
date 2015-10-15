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
map<pi, int> vpd;
int n, k;
int nums[1000007];
ll l;

int pd(int w, int it){
    if(it > k) return 0;   
    if(vpd.find(mp(w, it)) != vpd.end()) return vpd[mp(w, it)];

    int aux = 0;
    f(n, i){
        if(i + it*n > l-1) break;
        if(nums[w] <= nums[i]){
            if(i > (l-1)%n) {
                aux = (aux + (((l+n-1)/n-it-1)%MOD + pd(i, it+1))%MOD)%MOD;
            }
            else{
                aux = (aux + (((l+n-1)/n-it)%MOD + pd(i, it+1))%MOD)%MOD;
            }
        }
    }
    vpd[mp(w, it)] = aux;
    return aux;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> l >> k;
    f(n, i){
        cin >> nums[i];
    }
    nums[n] = 0;
    int ans = pd(n, 0);
    cout << ans << "\n";
}
