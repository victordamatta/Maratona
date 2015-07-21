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
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define MOD 1000000007
#define OO INT_MAX
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int primes[10007], auxp[10007];

int bs(int lo, int hi, int target){
    int mid;
    while(lo!=hi){
        mid = (hi+lo)/2;
        if(mid==lo) break;
        if(primes[mid] <= target) lo = mid;
        else hi = mid-1;
    }
    if(primes[hi] <= target) return hi;
    else return lo;
}

int main(){
    std::ios::sync_with_stdio(false);
    int psize = 0;
    ms(auxp, 1);
    for(int i=2; i<=10000; i++){
        if(!auxp[i]) continue;
        primes[psize++] = i;
        for(int j=i*i; j<=10000; j+=i){
            auxp[j] = 0;
        }
    }
    int n;
    while(cin >> n, n!=0){
        int where = bs(0, psize-1, n), was;
        was = 0;
        int ans=0, sum=0;
        for(int i=0; i<=where; i++){
            if(sum+primes[i] < n) sum+=primes[i];
            else if(sum+primes[i]==n){
                sum+=primes[i];
                ans++;
            }
            else{
                while(sum+primes[i] > n){
                    sum-=primes[was];
                    was++;
                }
                sum += primes[i];
                if(sum==n) ans++;
            }
        }
        cout << ans << "\n";
    }
}
