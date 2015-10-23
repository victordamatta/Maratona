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
int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, 1, -1};
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
        f(4, i){
            if(aux.fst+xs[i] >= n || aux.fst+xs[i] < 0 || aux.scd+ys[i] < 0 || aux.scd+ys[i]>=m2)
                continue;
            if(mat[aux.fst+xs[i]][aux.scd+ys[i]] == 0){
                cout << m[aux] + 1 << "\n";
                return 0;
            }
            else if(mat[aux.fst+xs[i]][aux.scd+ys[i]] == 1 && m.find(mp(aux.fst+xs[i], aux.scd+ys[i])) == m.end()){
                q.push(mp(aux.fst+xs[i], aux.scd+ys[i]));
                m[mp(aux.fst+xs[i], aux.scd+ys[i])] = m[aux] + 1;
            }
        }
    }
    return 0;
}
