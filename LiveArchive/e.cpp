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
int n;
typedef vector<vector<int> > Mat;

Mat mult (Mat mat, Mat nat) {
    Mat ans(2);
    ans[0].pb (((long long) mat[0][0]*nat[0][0]%MOD + (long long) mat[0][1]*nat[1][0]%MOD) % MOD);
    ans[0].pb (((long long) mat[0][0]*nat[0][1]%MOD + (long long) mat[0][1]*nat[1][1]%MOD) % MOD);
    ans[1].pb (((long long) mat[1][0]*nat[0][0]%MOD + (long long) mat[1][1]*nat[1][0]%MOD) % MOD);
    ans[1].pb (((long long) mat[1][0]*nat[0][1]%MOD + (long long) mat[1][1]*nat[1][1]%MOD) % MOD);
    return ans;
}

Mat Exp (Mat mat, int e) {
    /* cout << e << endl; */
    if (e == 1) return mat;
    if (e % 2 == 0) return Exp (mult (mat, mat), e/2);
    return mult (mat, Exp (mat, e-1));
}

int fib (int e) {
    Mat mat(2);
    mat[0].pb (1);
    mat[0].pb (1);
    mat[1].pb (1);
    mat[1].pb (0);
    Mat ans = Exp (mat, e-1);
    /* for (auto v: ans) { */
    /*     for (int i: v) { */
    /*         cout << i << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    return ans[0][0];
}

int main(){
    int t;
    scanf ("%d", &t);
    int past = 0;
    while (t--) {
        scanf ("%d", &n);
        int ans = fib (n);
        printf ("%d\n", ans);
    }
}
