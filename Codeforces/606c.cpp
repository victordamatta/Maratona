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
    int n;
    cin >> n;
    int pos[100007];
    f(n, i){
        int aux;
        cin >> aux;
        pos[aux] = i;
    }
    int x = 2, maxi = 1, cur = 1;
    while (x <= n){
        if(pos[x] > pos[x-1]) cur++;
        else cur = 1;
        if(cur > maxi) maxi = cur;
        x++;
    }
    cout << n - maxi << "\n";
}
