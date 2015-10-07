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

int vert[100], hor[100], n;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    int ans[10000], s = 0;
    ms(vert, 0);
    ms(hor, 0);
    int aux1, aux2;
    f(n*n, i){
        cin >> aux1 >> aux2;
        if ((!vert[aux1]) && (!hor[aux2])){
            vert[aux1] = 1;
            hor[aux2] = 1;
            ans[s++] = i;
        }
    }
    for (int i = 0; i<s; i++){
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}
