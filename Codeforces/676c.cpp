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
int n, k, k1;
string s;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> k1 >> s;
    int maxi = 0;
    k = k1;
    int cur = 0;
    int start = 0;
    if (k == 0) {
        char c = s[0];
        f (n, i) {
            if (s[i] == c) {
                cur++;
            }
            else {
                c = s[i];
                cur = 1;
            }
            if (cur > maxi) maxi = cur;
        }
        cout << maxi << endl;
        return 0;
    }
    f (n, i) {
        if (s[i] == 'a') {
            cur++;
        }
        else {
            if (k > 0) {
                cur++;
                k--;
            }
            else {
                while (s[start] != 'b') {
                    cur--;
                    start++;
                }
                start++;
            }
        }
        if (cur > maxi) maxi = cur;
    }
    cur = 0;
    start = 0;
    k = k1;
    f (n, i) {
        if (s[i] == 'b') {
            cur++;
        }
        else {
            if (k > 0) {
                cur++;
                k--;
            }
            else {
                while (s[start] != 'a') {
                    cur--;
                    start++;
                }
                start++;
            }
        }
        if (cur > maxi) maxi = cur;
    }
    cout << maxi << endl;
}
