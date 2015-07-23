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

int fib[105];
char in[107], ans[107];

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        f(n, i){
            cin >> fib[i];
        }
        int aux=0;
        char c;
        while(aux < n){
            cin >> c;
            if('A'<=c && c <= 'Z'){
                in[aux++] = c;
            }
        }
        while(cin.peek()!='\n'){
            cin.get();
        }
        map<int, char> m;
        f(n, i){
            m[fib[i]] = in[i];
        }
        int a=1, b=2;
        aux = 0;
        map<int, char>::iterator it;
        while(aux < n){
            it = m.find(a);
            if(it != m.end()){
                cout << it->second;
                aux++;
            }
            else cout << " ";
            swap(a, b);
            b = a+b;
        }
        cout << "\n";
    }
}
