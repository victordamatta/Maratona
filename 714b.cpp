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
const int OO = 1000000001;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
int vet[100007];

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    set<int> s;
    f (n, i) {
        cin >> vet[i];
        s.insert (vet[i]);
    }
    if (s.size () > 3) cout << "NO\n";
    else if (s.size () == 3) {
        vi v;
        for (int x: s) v.pb (x);
        int dif1 = v[1] - v[0], dif2 = v[2] - v[1]; 
        if (abs (dif1) == abs (dif2)) cout << "YES\n";
        else cout << "NO\n";
    }
    else cout << "YES\n";
}
