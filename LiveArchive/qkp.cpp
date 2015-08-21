
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

int mat[1007][1007], n, m;

void queen(int x, int y){
    for(int i=x-1; i>=0; i--){
        if(mat[i][y] == -1) break;
        mat[i][y] = 0;
    }
    for(int i=x+1; i<n; i++){
        if(mat[i][y] == -1) break;
        mat[i][y] = 0;
    }
    for(int i=y-1; i>=0; i--){
        if(mat[x][i] == -1) break;
        mat[x][i] = 0;
    }
    for(int i=y+1; i<m; i++){
        if(mat[x][i] == -1) break;
        mat[x][i] = 0;
    }
    int x2=x+1, y2=y+1;
    while(x2 < n && y2 < m){
        if(mat[x2][y2] == -1) break;
        mat[x2][y2] = 0;
        x2++; y2++;
    }
    x2=x-1; y2=y-1;
    while(x2 >= 0 && y2 >= 0){
        if(mat[x2][y2] == -1) break;
        mat[x2][y2] = 0;
        x2--; y2--;
    }
    x2=x-1; y2=y+1;
    while(x2 >= 0 && y2 < m){
        if(mat[x2][y2] == -1) break;
        mat[x2][y2] = 0;
        x2--; y2++;
    }
    x2=x+1; y2=y-1;
    while(x2 < n && y2 >= 0){
        if(mat[x2][y2] == -1) break;
        mat[x2][y2] = 0;
        x2++; y2--;
    }
}

void knight(int x, int y){
    int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2}, dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    f(8, i){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m)
            if(mat[x+dx[i]][y+dy[i]]==1) mat[x+dx[i]][y+dy[i]] = 0;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int cont = 0;
    while(cin >> n >> m, n!=0 || m!=0){
        cont++;
        int k1, k2, k3;
        cin >> k1;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                mat[i][j] = 1;
        pair<int, int> q[200];
        f(k1, i){
            int x, y;
            cin >> x >> y;
            mat[x-1][y-1] = -1;
            q[i].first = x-1;
            q[i].second = y-1;
        }
        cin >> k2;
        pair<int, int> c[200];
        f(k2, i){
            int x, y;
            cin >> x >> y;
            mat[x-1][y-1] = -1;
            c[i].first = x-1;
            c[i].second = y-1;
        }
        cin >> k3;
        f(k3, i){
            int x, y;
            cin >> x >> y;
            mat[x-1][y-1] = -1;
        }
        f(k1, i){
            queen(q[i].first, q[i].second);
        }
        f(k2, i){
            knight(c[i].first, c[i].second);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //cout << mat[i][j] << " ";
                if(mat[i][j]==1) ans++;
            }
            //cout << "\n";
        }
        cout << "Board " << cont << " has " << ans << " safe squares.\n";
    }
}
