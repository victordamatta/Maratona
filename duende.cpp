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
int mat[15][15];
map<pi, int> m;
int n, m2;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m2;
    int x, y;
    f(n, i){
        f(m2, j){
            cin >> mat[i][j];
            if(mat[i][j] == 3){
                x = i;
                y = j;
            }
        }
    }
    queue<pi> q;
    q.push(mp(x, y));
    m[mp(x, y)] = 0;
    int ans;
    while(!q.empty()){
        pi aux = q.front();
        q.pop();
        cout << aux.fst << " " << aux.scd << "\n";
        if(aux.fst < n - 1){
            if(mat[aux.fst + 1][aux.scd] == 0){
                cout << m[aux] + 1 << "\n";
                return 0;
            }
            else if(mat[aux.fst + 1][aux.scd] == 1 && m.find(mp(aux.fst+1, aux.scd))== m.end()){
                q.push(mp(aux.fst + 1, aux.scd));
                m[mp(aux.fst+1, aux.scd)] = m[aux] + 1;
            }
        }
        else if(aux.fst > 0){
            if(mat[aux.fst - 1][aux.scd] == 0){
                cout << m[aux] + 1 << "\n";
                return 0;
            }
            else if(mat[aux.fst - 1][aux.scd] == 1 && m.find(mp(aux.fst-1, aux.scd))== m.end()){
                q.push(mp(aux.fst - 1, aux.scd));
                m[mp(aux.fst-1, aux.scd)] = m[aux] + 1;
            }
        }
        else if(aux.scd > 0){
            if(mat[aux.fst][aux.scd - 1] == 0){
                cout << m[aux] + 1 << "\n";
                return 0;
            }
            else if(mat[aux.fst][aux.scd - 1] == 1 && m.find(mp(aux.fst, aux.scd-1))== m.end()){
                q.push(mp(aux.fst, aux.scd - 1));
                m[mp(aux.fst, aux.scd-1)] = m[aux] + 1;
            }
        }
        else if(aux.scd < m2 - 1){
            if(mat[aux.fst][aux.scd + 1] == 0){
                cout << m[aux] + 1 << "\n";
                return 0;
            }
            else if(mat[aux.fst][aux.scd + 1] == 1 && m.find(mp(aux.fst, aux.scd+1))== m.end()){
                q.push(mp(aux.fst, aux.scd + 1));
                m[mp(aux.fst, aux.scd+1)] = m[aux] + 1;
            }
        }
    }
    return 0;
}
