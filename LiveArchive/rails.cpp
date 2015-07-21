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
    int n;
    int seq[1007];
    while(cin >> n, n!=0){
        int aux;
        while(cin >> aux, aux != 0){
            stack<int> stc;
            queue<int> q;
            int ok = 1;
            f(n, i){
                q.push(i+1);
            }
            seq[0] = aux;
            for(int i=1; i<n; i++){
                cin >> seq[i];
            }
            f(n, i){
                if(stc.empty() && q.empty()) break;
                if(stc.empty() && seq[i]<q.front()){
                    ok = 0;
                    break;
                }
                else if(!stc.empty() && seq[i]!=stc.top() && !q.empty() && seq[i]<q.front()){
                    ok = 0;
                    break;
                }
                else if(!stc.empty() && seq[i]!=stc.top() && q.empty()){
                    ok = 0;
                    break;
                }
                if(!stc.empty() && seq[i] == stc.top()){
                    stc.pop();
                }
                else if(!q.empty() && seq[i] >= q.front()){
                    while(seq[i] > q.front()){
                        stc.push(q.front());
                        q.pop();
                    }
                    q.pop();
                }
            }
            if(ok) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n";
    }
}
