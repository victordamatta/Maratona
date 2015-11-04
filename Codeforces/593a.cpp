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
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 0x3f3f3f;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int mat[300][300];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    f(n, i){
        string a;
        char c1, c2;
        int num = 0, ok = 1;
        cin >> a;
        int j = 1;
        c1 = a[0];
        c2 = a[0];
        while(j < a.length() && a[j] == c1){
            j++;
        }
        if(j < a.length()) c2 = a[j];
        while(j < a.length()){
            if(a[j] != c1 && a[j] != c2) ok = 0;
            j++;
        }
        if(ok){
            if(c1 == c2){
                for(char x = 'a'; x <= 'z'; x++){
                    mat[x][c1] += a.length();
                    mat[c1][x] += a.length();
                }
            }
            else{
                mat[c1][c2] += a.length();
                mat[c2][c1] += a.length();
            }
        }
    }
    int maxi = 0;
    for(char i = 'a'; i <= 'z'; i++){
        for(char j = 'a'; j<= 'z'; j++){
            if(i != j)
                maxi = max(maxi, mat[i][j]+mat[j][i]);
            else maxi = max(maxi, mat[i][j]);
        }
    }
    cout << maxi/2 << "\n";
}
