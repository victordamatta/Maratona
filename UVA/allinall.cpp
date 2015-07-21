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

int main(){
    std::ios::sync_with_stdio(false);
    string a, b;
    while(cin.peek()!=EOF){
        cin >> a >> b;
        int ok=1;
        string::iterator it1 = a.begin(), it2 = b.begin();
        while(it1!=a.end()){
            if(it2 == b.end()){
                ok = 0;
                break;
            }
            if(*it1 == *it2){
                it1++;
                it2++;
            }
            else it2++;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
        cin.get();
    }
}
