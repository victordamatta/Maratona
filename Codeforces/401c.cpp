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
    int n, m;
    cin >> n >> m;
    if(m < n-1 || m > 2*n+2) cout << -1 << "\n";
    else{
        while(m > n && n > 0 && m > 1){
            cout << "110";
            m -= 2;
            n--;
        }
        while(n && m){
            if(m>=n)
                cout << "10";
            else
                cout << "01";
            m--;
            n--;
        }
        while(n){
            cout << "0";
            n--;
        }
        while(m){
            cout << "1";
            m--;
        }
        cout << "\n";
    }
}
