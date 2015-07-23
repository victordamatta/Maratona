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

int mod(int a, int b){
    if(a > b) return a%b;
    else return mod(a+b, b);
}

int main(){
    std::ios::sync_with_stdio(false);
    //ONLY RIGHT FOR SIMMETRICAL HEXAGONS
    int hex[6], maxi, aux=0;
    f(6, i){
        cin >> hex[i];
        if(hex[i] > aux){
            maxi = i;
            aux = hex[i];
        }
    }
    int size = hex[maxi] + hex[mod(maxi+1, 6)] + hex[mod(maxi-1, 6)];
    int fix[3];
    fix[0] = hex[mod(maxi+1, 6)];
    fix[1] = hex[mod(maxi-1, 6)];
    fix[2] = hex[mod(maxi+3, 6)];
    int ans = 0;
    aux = 1;
    for(int i=0; i<size; i++){
        ans += aux;
        aux += 2;
    }
    int fixs = 0;
    for(int i=0; i<3; i++){
        aux = 1;
        for(int j=0; j<fix[i]; j++){
            fixs += aux;
            aux += 2;
        }
    }
    cout << ans-fixs << "\n";
}
