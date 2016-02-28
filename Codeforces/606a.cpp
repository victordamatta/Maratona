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
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, z;
    cin >> x >> y >> z;
    int needs = 0, has = 0;
    x -= a;
    y -= b;
    z -= c;
    if (x > 0) needs += x;
    else has += (-x)/2;
    if (y > 0) needs += y;
    else has += (-y)/2;
    if (z > 0) needs += z;
    else has += (-z)/2;
    if(has >= needs) cout << "Yes\n";
    else cout << "No\n";
}
