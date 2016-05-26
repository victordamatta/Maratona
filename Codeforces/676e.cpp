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
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll> > vpi;
typedef set<ll> si;
typedef set<ll>::iterator sit;
const ll OO = 1000000000;
//REMEMBER LONG LONG ll
//REMEMBER TO INITIALZE THINGS
int main(){
    std::ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if (k == 0) {
        char c;
        cin >> c;
        if (c == '?') {
            int aux = 1;
            f (n, i) {
                string c;
                cin >> c;
                if (c.compare ("?") == 0) {
                    aux++;
                }
            }
            if ((n+1-aux) % 2 == 0) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
        else if (c == '0') {
            cout << "Yes\n";
        }
        else cout << "No\n";
        return 0;
    }
    ll sum = 0;
    bool ok = true;
    f (n+1, i) {
        string c;
        cin >> c;
        if (c.compare ("?") == 0) {
            if (n % 2 == 1) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
            return 0;
        }
        ll num = stoi (c);
        sum += num;
        if (sum % k != 0) {
            ok = false;
        }
        sum /= k;
    }
    if (sum != 0) ok = false;

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}
