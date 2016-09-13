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
    int n;
    cin >> n;
    
    int ans1[4];
    int ans2[4];

    int base = 2;
    int u = 1, l = 1, d = n, r = n;
    while (u < d) {
        int mid = (u + d) / 2;
        if (mid == d || mid == u) break;
        cout << "? " << mid << " " << l << " " << u << " " << r << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) u = mid + 1;
        else d = mid;
    }
    ans1[0] = d;

    //cout << "ans10" << endl;

    base = 1;
    u = 1, l = 1, d = n, r = n;
    while (u < d) {
        int mid = (u + d) / 2;
        if (mid == d || mid == u) break;
        cout << "? " << mid << " " << l << " " << u << " " << r << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) u = mid + 1;
        else d = mid;
    }
    ans2[0] = d;

    //cout << "ans20" << endl;

    base = 2;
    u = 1, l = 1, d = n, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid == l || mid == r) break;
        cout << "? " << d << " " << mid << " " << u << " " << r << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) r = mid - 1;
        else l = mid;
    }
    ans1[1] = l;

    //cout << "ans11" << endl;

    base = 1;
    u = 1, l = 1, d = n, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid == l || mid == r) break;
        cout << "? " << d << " " << mid << " " << u << " " << r << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) r = mid - 1;
        else l = mid;
    }
    ans2[1] = l;

    //cout << "ans21" << endl;

    base = 2;
    u = 1, l = 1, d = n, r = n;
    while (u < d) {
        int mid = (u + d) / 2;
        if (mid == u || mid == d) break;
        cout << "? " << d << " " << l << " " << mid << " " << r << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) d = mid - 1;
        else u = mid;
    }
    ans1[2] = u;

    //cout << "ans12" << endl;

    base = 1;
    u = 1, l = 1, d = n, r = n;
    while (u < d) {
        int mid = (u + d) / 2;
        if (mid == u || mid == d) break;
        cout << "? " << d << " " << l << " " << mid << " " << r << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) d = mid - 1;
        else u = mid;
    }
    ans2[2] = u;

    //cout << "ans22" << endl;

    base = 2;
    u = 1, l = 1, d = n, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid == r || mid == l) break;
        cout << "? " << d << " " << l << " " << u << " " << mid << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) l = mid + 1;
        else r = mid;
    }
    ans1[3] = r;

    //cout << "ans13" << endl;

    base = 1;
    u = 1, l = 1, d = n, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid == r || mid == l) break;
        cout << "? " << d << " " << l << " " << u << " " << mid << endl;
        fflush (stdout);
        int aux;
        cin >> aux;
        if (aux < base) l = mid + 1;
        else r = mid;
    }
    ans2[3] = r;

    //cout << "ans23" << endl;

    cout << "!";
    f (4, i) cout << " " << ans1[i];
    f (4, i) cout << " " << ans2[i];
    cout << endl;
    fflush (stdout);
    return 0;
}
