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
#define f(x, let) for(ll let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
#define vi vector<ll>
#define si set<ll>
#define sit set<ll>::iterator
#define MOD 1000000007
#define OO LLONG_MAX/100
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

ll vpd[11][101];
ll vpd2[11][101];
ll choices[101];
ll n, x;
ll num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll pd(ll k, ll m){
    if(k==10) return OO;
    if(m < 0) return OO;
    if(m==0) return 0;
    if(vpd[k][m]!=-1) return vpd[k][m];

    vpd[k][m] = min(1 + pd(0, m-num[k]), pd(k+1, m));

    return vpd[k][m];
}
void pd3(ll k, ll m, int b){
    if(m==0) return;

    int ans, ans2;
    ans = 1+pd(0, m-num[k]);
    ans2 = pd(k+1, m);

    if(ans < ans2){
        if(!b){
            choices[x] = k;
            x++;
            pd3(0, m-num[k], 0);
        }
        else{
            choices[x] = min(choices[x], k);
            x++;
            pd3(0, m-num[choices[x-1]], 0);
        }
    }
    else if(ans2 < ans){
        if(!b)
            pd3(k+1, m, 0);
        else
            pd3(k+1, m, 1);
    }
    else{
        if(x!=0 || k!=0)
            choices[x] = min(choices[x], k);
        pd3(k+1, m, 1);
    }
}
ll pd2(ll k, ll m){
    if(k==10) return -OO;
    if(m < 0) return -OO;
    if(m==0) return 0;
    if(vpd2[k][m]!=-1) return vpd2[k][m];

    vpd2[k][m] = max(1 + pd2(1, m-num[k]), pd2(k+1, m));
    
    return vpd2[k][m];
}
void pd4(ll k, ll m){
    if(m==0) return;

    int ans, ans2;
    ans = 1+pd2(0, m-num[k]);
    ans2 = pd2(k+1, m);

    if(ans > ans2){
        choices[x] = k;
        x++;
        pd4(0, m-num[k]);
    }
    else if(ans2 > ans){
        pd4(k+1, m);
    }
    else{
        choices[x] = max(choices[x], k);
        pd4(k+1, m);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ms(vpd, -1);
        ms(vpd2, -1);

        x = 0;
        ms(choices, 11);
        pd(0, n);
        pd3(0, n, 0);
        for(int i=0; i<x; i++){
            cout << choices[i];
        }

        cout << " ";

        x = 0;
        ms(choices, 0);
        pd2(0, n);
        pd4(0, n);
        for(int i=0; i<x; i++){
            cout << choices[i];
        }

        cout << "\n";
    }
}
