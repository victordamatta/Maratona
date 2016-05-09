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

int main(){
    std::ios::sync_with_stdio(false);
    int a[107][107], ar[107][107], ad[107][107], al[107][170];
    int n;
    cin >> n;
    f (n, i) {
        f (n, j) {
            cin >> a[i][j];
            ar[j][n-i] = a[i][j];
            ad[n-j][n-i] = a[i][j];
            al[n-j][i] = a[i][j];
        }
    }
    f (n, i) {
        f (n, j) {
            cout << a[i][j] || ar[i][j] || ad[i][j] || al[i][j] << " ";
        }
        cout << endl;
    }
}
