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
    int a, b, t, n, m;
    while(cin.peek()!=EOF){
        cin >> n;
        m = n;
        a = 1;
        b = 1;
        t = 1;
        n--;
        while(n){
            if(t==1){
                while(a!=1){
                    b++;
                    a--;
                    n--;
                    if(n==0) break;
                }
                if(n==0) break;
                b++;
                n--;
                if(n==0) break;
                t = 0;
            }
            else{
                while(b!=1){
                    b--;
                    a++;
                    n--;
                    if(n==0) break;
                }
                if(n==0) break;
                a++;
                n--;
                if(n==0) break;
                t = 1;
            }
        }
        cout << "TERM " << m << " IS " << a << "/" << b << "\n";
        cin.get();
    }
}
