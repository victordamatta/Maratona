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

int n;
multiset<int> s;
vi v;

int gcd(int a, int b){
    int aux;
    while(b != 0) {
        aux = b;
        b = a%b;
        a = aux;
    } 
    return a;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    int aux;
    f(n, i){
        f(n, j) {
            cin >> aux;
            s.insert(aux);
        }
    } 
    multiset<int>::iterator it;
    while(!s.empty()){
        aux = *s.rbegin();
        it = s.find(aux);
        s.erase(it);
        f(v.size(), i){
            it = s.find(gcd(aux, v[i]));
            s.erase(it);
            it = s.find(gcd(aux, v[i]));
            s.erase(it);
        }
        v.pb(aux);
    }
    f(v.size(), i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}
