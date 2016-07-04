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
int value (string d) {
    int val = 0, aces = 0;
    f (d.length (), i) {
        if (d[i] > '1' && d[i] <= '9') val += d[i] - '0';
        else if (d[i] == 'K' || d[i] == 'Q' || d[i] == 'J' || d[i] == 'T') val += 10;
        else {
            aces++;
        }
    }
    if (aces) {
        if (val + 11 + aces - 1 <= 21) val = val + 11 + aces - 1;
        else val = val + aces;
    }
    return val;
}

bool bust (string s) {
    int val = 0, aces = 0;
    f (s.length (), i) {
        if (s[i] > '1' && s[i] <= '9') val += s[i] - '0';
        else if (s[i] == 'K' || s[i] == 'Q' || s[i] == 'J' || s[i] == 'T') val += 10;
        else aces++;
    }
    if (aces == 0) return val > 21;
    else return (val + 11 + (aces-1) > 21) && (val + aces > 21);
}

bool victory (string p, string d) {
    if (bust (p)) return false;
    if (bust (d)) return true;
    int vp = 0, vd = 0, ap = 0, ad = 0;
    f (p.length (), i) {
        if (p[i] > '1' && p[i] <= '9') vp += p[i] - '0';
        else if (p[i] == 'K' || p[i] == 'Q' || p[i] == 'J' || p[i] == 'T') vp += 10;
        else ap++;
    }
    f (d.length (), i) {
        if (d[i] > '1' && d[i] <= '9') vd += d[i] - '0';
        else if (d[i] == 'K' || d[i] == 'Q' || d[i] == 'J' || d[i] == 'T') vd += 10;
        else ad++;
    }
    if (ap) {
        if (vp + 11 + (ap-1) <= 21) vp = vp + 11 + (ap-1);
        else vp = vp + ap;
    }
    if (ad) {
        if (vd + 11 + (ad-1) <= 21) vd = vd + 11 + (ad-1);
        else vd = vd + ad;
    }
    return vp >= vd;
}

int main(){
    std::ios::sync_with_stdio(false);
    string s;
    while (cin >> s, s.compare ("JOKER") != 0) {
        string player = "";
        string dealer = "";
        player += s[0];
        dealer += s[1];
        player += s[2];
        dealer += s[3];
        bool ok = false;
        string p = player;
        string d = dealer;
        for (int i = 4; i < s.length (); i++) {
            if (value (d) < 17) d += s[i];
            else break;
        }
        ok = ok || victory (p, d);
        for (int i = 4; i < s.length (); i++) {
            d = dealer;
            p += s[i];
            for (int j = i+1; j < s.length (); j++) {
                if (value (d) < 17) d += s[j];
                else break;
            }
            ok = ok || victory (p, d);
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
