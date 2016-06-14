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
#define pb push
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
string ans[10000000];

int main(){
    std::ios::sync_with_stdio(false);
    priority_queue<int> q;
    int n;
    cin >> n;
    int nans = 0;
    f (n, i) {
        string s;
        int aux;
        cin >> s;
        if (s.compare ("insert") == 0) {
            cin >> aux;
            q.push (-aux);
            ans[nans++] += s + " " + to_string (aux) + "\n";
        }
        else if (s.compare ("removeMin") == 0) {
            if (q.empty()) {
                ans[nans++] += "insert 1\n";
                ans[nans++] += s + "\n";
            }
            else {
                q.pop ();
                ans[nans++] += s + "\n";
            }
        }
        else {
            cin >> aux;
            if (q.empty ()) {
                ans[nans++] += "insert " + to_string (aux) + "\n";
                ans[nans++] += s + " " + to_string (aux) + "\n";
                q.push (-aux);
            }
            else if (q.top () == -aux) {
                ans[nans++] += s + " " + to_string (aux) + "\n";
            }
            else {
                while (!q.empty () && q.top () > -aux) {
                    ans[nans++] += "removeMin\n";
                    q.pop ();
                }
                if (!q.empty () && q.top () == -aux) {
                    ans[nans++] += s + " " + to_string (aux) + "\n";
                }
                else {
                    ans[nans++] += "insert " + to_string (aux) + "\n";
                    ans[nans++] += s + " " + to_string (aux) + "\n";
                    q.push (-aux);
                }
            }
        }
    }
    cout << nans << endl;
    f (nans, i) cout << ans[i];
}
