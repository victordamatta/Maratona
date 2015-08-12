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

int n;
double w;
double vet[200007];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> w;
    for(int i = 0; i < 2*n; i++){
        cin >> vet[i];
    }
    double hi, lo, mid;
    sort(vet, vet+2*n);
    hi = w/(3*n);
    lo = 0;
    int ok = 1;
    while(hi - lo > 0.0000001){
        ok = 1;
        mid = (hi+lo)/2;
        for(int i=0; i<n; i++){
            if(vet[i] < mid) ok = 0;
        }
        for(int i=n; i<2*n && ok; i++){
            if(vet[i] < 2*mid) ok = 0;
        }
        if(ok) lo = mid;
        else hi = mid-0.0000001;
    }
    cout << 3*n*lo << "\n";
}
