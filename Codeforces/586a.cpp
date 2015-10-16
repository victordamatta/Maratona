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
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ps[200];
    f(n, i)
        cin >> ps[i];
    while(n > 0 && ps[n-1] == 0) n--;
    int i = 0;
    while(i < n && ps[i] == 0) i++;
    int ans = 0;
    while(i < n) {
        if (ps[i]) ans++;
        else {
            i++;
            if (ps[i]) ans+=2;
            else {
                while (i<n && ps[i+1] == 0) i++;
            }
        }
        i++;
    }
    cout << ans << "\n";
}
