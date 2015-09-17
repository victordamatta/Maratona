
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

int main(){
    std::ios::sync_with_stdio(false);
    int used[100007], avai[100007];
    int ans[100007];
    int n;
    cin >> n;
    for(int i=1; i<=n;i++)
        avai[i] = 1;
    int cont = 0;
    for(int i=0; i<n; i++){
        cin >> ans[i];
        if(avai[ans[i]])
            avai[ans[i]] = 0;
        else
            used[cont++] = i;
    }
    cont = 0;
    for(int i=1; i<=n; i++){
        if(avai[i]){
            ans[used[cont++]] = i;
        }
    }
    cout << ans[0];
    for(int i=1; i<n; i++){
        cout << " " << ans[i];
    }
    cout << "\n";

}
