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
int vpd[6007][7];
int calc[6007][7];
int coins[7];
int t;

int pd (int q, int k) {
    if (q > 6000) return OO;
    if (q < 0) return OO;
    if (k == -1 && q != 3000) return OO;
    if (k == -1) return 0;
    if (calc[q][k] == t) return vpd[q][k];
    int ans = OO;
    int aux = -100;
    while (aux <= 100) {
        ans = min (abs (aux) + pd (q-aux*coins[k], k-1), ans);
        aux++;
    }
    vpd[q][k] = ans;
    calc[q][k] = t;
    return ans;
}

int main(){
    scanf ("%d", &t);
    while (t) {
        double avg = 0.0;
        int maxi = 0;
        f (6, i) scanf ("%d", &coins[i]);
        for (int i = 1; i <= 100; i++) {
            int aux = pd (i+3000, 5);
            if (aux > maxi) maxi = aux;
            avg += aux;
        }
        avg /= 100;
        printf ("%.2lf %d\n", avg, maxi);
        t--;
    }
}
