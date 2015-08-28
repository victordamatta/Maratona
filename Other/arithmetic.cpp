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

int vpd[500007][9];
int w, d, v;
int ds[15];

int pd(int op, int dig, int num, int target){
    if(num > 5000000) return 0;
    if(op == 0 && num==target) return 1;
    if(op==0) return 0;
    if(dig==d) return 0;
    if(vpd[num][op] != -1) return vpd[num][op];

    vpd[num][op] = pd(op-1, 0, num+ds[dig], target) || pd(op-1, 0, num*ds[dig], target) || pd(op, dig+1, num, target);

    return vpd[num][op];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> w;
    cin >> d;
    f(d, i)
        cin >> ds[i];
    cin >> v;
    f(v, i){
        int ok = 1, aux;
        ms(vpd, -1);
        cin >> aux;
        for(int j = 0; j<d && ok; j++){
            if(pd(w, 0, ds[j], aux)) ok = 0;
        }
        if(ok) cout << "N\n";
        else cout << "Y\n";
    }
}
