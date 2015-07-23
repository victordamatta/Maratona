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
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<int>
#define si set<int>
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    int ok = 0;
    if(a2+a3 <= a1){
        if(b2 <= b1 && b3<=b1)
            ok = 1;
    }
    if(a2+a3 <= b1){
        if(b2 <= a1 && b3<=a1)
            ok = 1;
    }
    if(a2+b3 <= a1){
        if(b2 <= b1 && a3<=b1)
            ok = 1;
    }
    if(a2+b3 <= b1){
        if(b2 <= a1 && a3<=a1)
            ok = 1;
    }
    if(b2+a3 <= a1){
        if(a2 <= b1 && b3<=b1)
            ok = 1;
    }
    if(b2+a3 <= b1){
        if(a2 <= a1 && b3<=a1)
            ok = 1;
    }
    if(b2+b3 <= a1){
        if(a2 <= b1 && a3<=b1)
            ok = 1;
    }
    if(b2+b3 <= b1){
        if(a2 <= a1 && a3<=a1)
            ok = 1;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
