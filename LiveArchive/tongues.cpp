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
char vowels[] = {'a', 'i', 'y', 'e', 'o', 'u'};
char consonants[] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

char transform (char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
    }
    int pos = -1;
    f (6, i) {
        if (vowels[i] == c) {
            pos = i;
        }
    }
    if (pos != -1) return vowels[(pos+3)%6];
    f (20, i) {
        if (consonants[i] == c) {
            pos = i;
        }
    }
    return consonants[(pos+10)%20];
}

int main(){
    std::ios::sync_with_stdio(false);
    map<char, char> m;
    for (char c = 'a'; c <= 'z'; c++) {
        char d = transform (c);
        m[c] = d;
        m[c-32] = d-32;
    }
    string s;
    while (getline (cin, s)) {
        string ans = "";
        f (s.length (), i) {
            if (m.find (s[i]) == m.end ()) {
                ans += s[i];
            }
            else ans += m[s[i]];
        }
        cout << ans << endl;
    }
}
