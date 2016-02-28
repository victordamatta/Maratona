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
const int OO = 0x3f3f3f;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    int x, y, x0, y0;
    cin >> x >> y >> x0 >> y0;
    string s;
    cin >> s;
    cout << "1 ";
    set<pair<int, int> > ss;
    int nw = 1;
    ss.insert(mp(x0, y0));
    f(s.length()-1, i){
        if(s[i] == 'U'){
            if(x0 > 1) x0--;
        }
        else if(s[i] == 'D'){
            if(x0 < x) x0++;
        }
        else if(s[i] == 'L'){
            if(y0 > 1) y0--;
        }
        else{
            if(y0 < y) y0++;
        }
        if(ss.find(mp(x0, y0)) == ss.end()){
            cout << "1 ";
            nw++;
        }
        else cout << "0 ";
        ss.insert(mp(x0, y0));
    }
    cout << x*y - nw << "\n";
}
