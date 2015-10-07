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

int n, in[1007];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    int inf = 0;
    f(n, i) {
        cin >> in[i];
        if (in[i] <= inf){
            inf++;
            in[i] = OO;
        }
    }
    int d = -1, ans = 0;
    while (inf < n) {
        if (d == -1){
            for (int i = n-1; i>=0 && inf < n; i--) {
                if (in[i] <= inf){
                    inf++;
                    in[i] = OO;
                }
            }
        }
        else{
            f(n, i){
                if (in[i] <= inf){
                    inf++;
                    in[i] = OO;
                }
                
            }
        }
        d = -d;
        ans++;
    }
    cout << ans << "\n";
}
