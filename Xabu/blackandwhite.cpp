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
    int n, m, c, ans=0;
    while(cin >> n >> m >> c, n!=0){
        ans = 0;
        n -= 7;
        m -= 7;
        if(n > m) swap(m, n);
        while(m > n){
            if(c){
                ans += n;
                c = 0;
            }
            else{
                ans += n-1;
                c=1;
            }
            m--;
        }
        if(c){
            ans += m;
            c = 0;
        }
        else{
            ans+=m-1;
            c = 1;
        }
        m--;
        while(m){
            if(c){
                ans += 2*m;
                c = 0;
            }
            else{
                ans+=2*(m-1);
                c = 1;
            }
            m--;
        }
        cout << ans << "\n";
    }
}
