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

struct exam{
    ll a;
    ll b;
} vet[10000];

bool comp(exam c, exam d){
    if(c.a != d.a)
        return c.a < d.a;
    return c.b < d.b;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    f(n, i){
        ll a1, b1;
        cin >> a1 >> b1;
        vet[i].a = a1;
        vet[i].b = b1;
    }
    sort(vet, vet+n, comp);
    ll ans = min(vet[0].a, vet[0].b);
    ll prev = vet[0].a;
    for(int i=1; i<n; i++){
        if(vet[i].a != prev)
            if(vet[i].b < ans) vet[i].b = LLONG_MAX;
        ans = min(vet[i].a, vet[i].b);
    }
    cout << ans << "\n";
}
