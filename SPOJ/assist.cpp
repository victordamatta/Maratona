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
    vi primes;
    vector<int> sieve(40000, 0);
    int i = 2;
    while(primes.size()<3001){
        if(sieve[i]){
            i++;
            continue;
        }
        primes.pb(i);
        int j = i+1, k = i;
        while(j < 40000){
            if(!sieve[j]){
                k--;
                if(k==0){
                    sieve[j] = true;
                    k = i;
                }
            }
            j++;
        }
        i++;
    }
    int x;
    while(cin >> x, x != 0) {
        cout << primes[x-1] << "\n";
    }
}
