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
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
ll vet[10007];

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k, e, m;
        cin >> n >> k >> e >> m;
        f (n-1, i) {
            ll sum = 0;
            f (e, j) {
                int aux;
                cin >> aux;
                sum += aux;
            }
            vet[i] = sum;
        }
        sort (vet, vet+n-1);
        ll serg = 0;
        f (e-1, i) {
            int aux;
            cin >> aux;
            serg += aux;
        }
        ll ans = vet[n-k-1] - serg;
        if (ans < 0) cout << "0\n";
        else if (ans+1 > m) cout << "Impossible\n";
        else cout << ans+1 << "\n";
    }
}
