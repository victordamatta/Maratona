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
int last, n, startlas;
struct piece {
    int time[2];
    int on;
};

int read (string s, int i) {
    string aux = "";
    while (s[i] >= '0' && s[i] <= '9') {
        aux += s[i];
        i++;
    }
    return stoi (aux);
}

piece repeater (string s, int start) {
    piece ans;
    ans.time[0] = ans.time[1] = 0;

    int i = 0, j;
    while (i < s.length ()) {
        if (s[i] == '(') {
            j = i;
            while (s[j] != ')') j++;
            piece temp = repeater (s.substr (i+1, j-i), start);
            j = j+2;
            i = j;
            while (s[j] <= '9' && s[j] >= '0') j++;
            int aux = stoi (s.substr (i, j-i));
            i = j;

            if (temp.on == start) {
                ans.time[0] += temp.time[0]*aux;
                ans.time[1] += temp.time[1]*aux;
            }
            else {
                ans.time[0] += temp.time[0]*(aux/2 + aux%2);
                ans.time[1] += temp.time[1]*(aux/2 + aux%2);
                ans.time[0] += temp.time[1]*(aux/2);
                ans.time[1] += temp.time[0]*(aux/2);

                if (aux % 2) start = !start;
            }
        }
        else {
            j = i;
            while (s[j] <= '9' && s[j] >= '0') j++;
            int aux = stoi (s.substr (i, j-i));
            i = j;

            ans.time[start] += aux;
            start = !start;
        }
        i++;
    }
    ans.on = start;
    return ans;
}

void stretch (string s) {
    int i = 0, j;
    while (i < s.length ()) {
        if (s[i] == '(') {
            j = i;
            while (s[j] != ')') j++;
            int jj = j+1;
            int ii = jj;
            while (s[jj] <= '9' && s[jj] >= '0') jj++;
            int aux = stoi (s.substr (ii, jj-ii));
            for (int it = 0; it < aux; it++) {
                stretch (s.substr (i+1, j-i));
            }
            i = jj;
        }
        else {
            j = i;
            while (s[j] <= '9' && s[j] >= '0') j++;
            int aux = stoi (s.substr (i, j-i));
            i = j;

            int time = (!startlas)*aux;
            if (n - time <= 0) {
                last += n;
                return;
            }
            else {
                n -= time;
                last += aux;
            }
            startlas = !startlas;
        }
        i++;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    while (cin >> n, n != 0) {
        string pat;
        getline (cin, pat);
        getline (cin, pat);
        piece bulk = repeater (pat, 0);
        int ans = 0;
        int on = 0;
        if (bulk.on == 0) {
            int times = n/bulk.time[0];
            ans += (bulk.time[0]+bulk.time[1])*times;
            n %= bulk.time[0];
        }
        else {
            int times = n/(bulk.time[0]+bulk.time[1]);
            ans += 2*(bulk.time[0]+bulk.time[1])*times;
            n %= bulk.time[0] + bulk.time[1];
            ans += (bulk.time[0]+bulk.time[1])*(n/bulk.time[0]);
            n %= bulk.time[0];
            on = bulk.on;
        }

        last = 0;
        startlas = on;
        stretch (pat);
        ans += last;
        cout << ans << endl;
    }
}
