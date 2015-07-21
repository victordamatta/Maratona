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

int bs(int lo, int hi, int target){
    int mid = (lo+hi)/2;
    if(mid==lo){
        if(sizes[hi] <= target) return hi;
        return mid;
    }
    if(sizes[mid]<=target)
        return bs(mid, hi, target);
    else 
        return bs(lo, mid-1, target);
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    int size=1, cont=2, pir=1, cube;
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
    sort(sizes, sizes+size);
    while(cin >> n, n!=-1){
        int ans = 0;
        while(n>0){
            int aux = bs(0, size, n);
            n -= sizes[aux];
            ans++;
        }
        cout << ans << "\n";
    }
}
