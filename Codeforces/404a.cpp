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
#define f(x) for(int i=0; i<x; i++)
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

int n;
char mat[307][307];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    int ok = 1;
    char a, b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    a = mat[0][0];
    b = mat[0][1];
    for(int i=0; i<n && ok; i++){
        for(int j=0; j<n && ok; j++){
            if(i == j || i == n-1-j){
                if(mat[i][j]!=a)
                    ok = 0;
            }
            else{
                if(mat[i][j]!=b)
                    ok = 0;
            }
        }
    }
    if(ok && a!=b) cout << "YES\n";
    else cout << "NO\n";
}
