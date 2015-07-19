#include <iostream>
/*
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

void matmult(ll mat[51][51], ll k, ll size){
    ll mm[51][51];
    if(k==1) return;
    if(k%2==0){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                mm[i][j] = 0;
                for(int k=0; k<size; k++){
                    mm[i][j] += mat[i][k]*mat[k][j];
                    mm[i][j] = mm[i][j]%MOD;
                }
            }
        }
        matmult(mm, k/2, size);
    }
    else{
        ll m[51][51];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                m[i][j] = mat[i][j];
            }
        }
        matmult(mat, k-1, size);
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                mm[i][j] = 0;
                for(int k=0; k<size; k++){
                    mm[i][j] += m[i][k]*mat[k][j];
                    mm[i][j] = mm[i][j]%MOD;
                }
            }
        }
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            mat[i][j] = mm[i][j];
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    ll t, m, n, mat[51][51];
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cin >> mat[i][j];
            }
        }
        matmult(mat, n, m);
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
