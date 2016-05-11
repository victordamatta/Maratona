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
double dist (double x, double y, double i, double j) {
    return ((x-i)*(x-i) + (y-j)*(y-j));
}

int main(){
    std::ios::sync_with_stdio(false);
    double ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n;
    double tot = 0;
    double pb=1000000000000, mbx, mby, pa=1000000000000, max, may;
    cin >> n;
    f (n, i) {
        double x, y;
        cin >> x >> y;
        tot += 2 * dist (x, y, tx, ty);
        double a = dist (x, y, ax, ay);
        double b = dist (x, y, bx, by);
        if (a < pa && b < pb) {
            if (pa-a > pb-b) {
                max = x;
                may = y;
                pa = a;
            }
            else {
                mbx = x;
                mby = y;
                pb = b;
            }
        }
        else if (a < pa) {
            max = x;
            may = y;
            pa = a;
        }
        else if (b < pb) {
            mbx = x;
            mby = y;
            pb = b;
        }
    }
    tot -= dist (max, may, tx, ty);
    tot += dist (max, may, ax, ay);
    tot -= dist (mbx, mby, tx, ty);
    tot += dist (mbx, mby, bx, by);
    cout << tot << endl;
}
