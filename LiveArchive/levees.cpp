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
double x1, Y1, x2, y2, x3, y3, x4, y4;

struct quad {
    double area, per;
} quads[4];

double dist (double a, double b, double i, double j) {
    return sqrt ((i-a)*(i-a) + (j-b)*(j-b));
}

double comp (quad a, quad b) {
    if (a.area - b.area < 0.0001 && a.area - b.area > -0.0001) {
        return a.per > b.per;
    }
    return a.area > b.area;
}

int main(){
    std::ios::sync_with_stdio(false);
    while (cin >> x1 >> Y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4, x1 != 0.0 || Y1 != 0.0 || x2 != 0.0 || y2 != 0.0) {
        double t = (y2*(x4 - x2) - Y1*(x4 - x2) + (y4 - y2)*(x1 - x2))/((x4 - x2)*(y3 - Y1) - (y4 - y2)*(x3 - x1));
        double xc = x1 + (x3 - x1)*t;
        double yc = Y1 + (y3 - Y1)*t;

        double a = dist (x1, Y1, x2, y2);
        double b = dist (x1, Y1, xc, yc);
        double c = dist (x2, y2, xc, yc);
        quads[0].per = a + b + c;
        double p = (a+b+c)/2.0;
        quads[0].area = sqrt (p*(p-a)*(p-b)*(p-c));

        a = dist (x2, y2, x3, y3);
        b = dist (x3, y3, xc, yc);
        c = dist (x2, y2, xc, yc);
        quads[1].per = a + b + c;
        p = (a+b+c)/2.0;
        quads[1].area = sqrt (p*(p-a)*(p-b)*(p-c));

        a = dist (x3, y3, x4, y4);
        b = dist (x3, y3, xc, yc);
        c = dist (x4, y4, xc, yc);
        quads[2].per = a + b + c;
        p = (a+b+c)/2.0;
        quads[2].area = sqrt (p*(p-a)*(p-b)*(p-c));

        a = dist (x1, Y1, x4, y4);
        b = dist (x1, Y1, xc, yc);
        c = dist (x4, y4, xc, yc);
        quads[3].per = a + b + c;
        p = (a+b+c)/2.0;
        quads[3].area = sqrt (p*(p-a)*(p-b)*(p-c));

        sort (quads, quads+4, comp);
        f (4, i) {
            cout << fixed << setprecision(3) << quads[i].area << " " << quads[i].per;
            if (i != 3) cout << " ";
            else cout << endl;
        }
    }
}
