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

int sizes[500000];
int vpd[200][500000];
int size;

int pd(int k, int n){
    if(n==0) return 0;
    if(n < 0) return INT_MAX - 500000;
    if(k==size) return INT_MAX - 500000;
    if(vpd[k][n] != -1) return vpd[k][n];

    vpd[k][n] = min(1+pd(0, n-sizes[k]), pd(k+1, n));

    return vpd[k][n];
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    size = 1;
    int cont=2, pir=1, cube;
    sizes[0] = 1;
    while(pir <= 400000){
        cube = cont*cont*cont;
        if(cube <=400000){
            sizes[size++] = cube;
        }
        pir += cont*cont;
        sizes[size++] = pir;
        cont++;
    }
    size--;
    ms(vpd, -1);
    while(cin >> n, n!=-1){
        int ans = pd(0, n);
        cout << ans << "\n";
    }
}
