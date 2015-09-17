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
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<ll>
#define si set<ll>
#define sit set<ll>::iterator
#define MOD 1000000007
#define OO 0x3f3f3f
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

//ll collatz[100000007];
map<ll, ll>m;

ll col (ll n){
    if (n == 1) return 0;
    if(m.find(n)!=m.end()) return m[n];

    ll collatz;
    if(n%2==0) collatz = 1+col(n/2);
    else collatz = 1+col(3*n+1);

    m[n] = collatz;

    return collatz;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll aux, max, maxc=0;
    //ms(collatz, -1);
    for(ll i = 2; i<1000000; i++){
        aux = col(i);
        if(aux>maxc){
            maxc = aux;
            max = i;
        }
    }
    cout << max << "\n";
}
