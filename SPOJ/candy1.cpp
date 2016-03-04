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
const int OO = 0x3f3f3f;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    int n, candies[10007], sum;
    while (cin >> n, n != -1) {
        sum = 0;
        ms(candies, 0);
        f(n, i) {
            cin >> candies[i];
            sum += candies[i];
        }
        if (sum % n != 0) cout << -1 << "\n";
        else {
            sum /= n;
            int p = 0;
            f(n, i) {
                if (candies[i] < sum) {
                    p += sum - candies[i];
                }
            }
            cout << p << "\n";
        }
    }
}
