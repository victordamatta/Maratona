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
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS
void flip (string& s, int end) {
    for (int i = 0; i <= end/2; i++) {
        swap (s[i], s[end-i]);
        if (s[i] == '+') s[i] = '-';
        else s[i] = '+';
        if (end-i != i) {
            if (s[end-i] == '+') s[end-i] = '-';
            else s[end-i] = '+';
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        string ss, s = "";
        char c = 'c';
        cin >> ss;
        for (int i = 0; i < ss.length (); i++) {
            if (ss[i] != c) s += ss[i];
            c = ss[i];
        }

        int ans = 0;
        int end = s.size () - 1;
        while (end >= 0) {
            if (s[end] == '+') end--;
            else if (s[end] == '-' && s[0] == '+') {
                flip (s, 0);
                flip (s, end);
                ans += 2;
            }
            else {
                flip (s, end);
                ans++;
            }
        }
        cout << "Case #" << k << ": " << ans << endl;
    }
}
