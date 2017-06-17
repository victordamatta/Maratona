#include <bits/stdc++.h>
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
    int h, m, t = 0;
    scanf("%d:%d", &h, &m);
    if (h == 23) {
        if (((h%10)*10 + h/10) < m) {
            t += 60 - m;
            printf ("%d\n", t);
            return 0;
        }
    }
    while ((16 <= h && h <= 19) || (6 <= h && h <= 9)) {
        if (m != 0) {
            t += 60 - m;
            m = 0;
            h++;
        }
        else {
            t += 60;
            h++;
        }
    }
    if (((h%10)*10 + h/10) < m) {
        t += 60 - m;
        m = 0;
        h++;
    }
    t += ((h%10)*10 + h/10) - m;
    printf ("%d\n", t);
}
