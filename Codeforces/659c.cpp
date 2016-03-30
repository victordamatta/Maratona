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
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    int has[100007];
    int j = 0, k = 0;
    cin >> n >> m;
    ms (has, 0);
    f (n, i) {
        cin >> has[i];
    }
    has[n] = 1000000007;
    sort (has, has+n);
    int ans = 0;
    vi an;
    while (m > 0) {
        if (j+1 < has[k]) {
            if (m >= j+1) {
                ans++;
                an.pb (j+1);
                m -= j+1;
            }
            else m = 0;
        }
        j++;
        if (j+1 > has[k]) k++;
    }
    cout << ans << endl;
    f (an.size (), i) {
        cout << an[i] << " ";
    }
    cout << "\n";
}
