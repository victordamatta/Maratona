#include <iostream>
#define f(x, let) for(int let=0; let<x; let++)
#define MOD 1000000009
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

void matcopy(ll m[3][3], ll mm[3][3]){
    f(3, i){
        f(3, j){
            m[i][j] = mm[i][j];
        }
    }
}

void matmult(ll m[3][3], ll mm[3][3], ll ans[3][3]){
    f(3, i){
        f(3, j){
            ans[i][j] = 0;
            f(3, k){
                ans[i][j] += m[i][k]*mm[k][j];
                ans[i][j] = ans[i][j]%MOD;
            }
        }
    }
}

void matexp(ll mat[3][3], ll k){
    ll m[3][3];
    if(k==1) return;
    if(k%2==0){
        matmult(mat, mat, m);
        matexp(m, k/2);
    }
    else{
        ll mm[3][3];
        matcopy(mm, mat);
        matexp(mat, k-1);
        matmult(mm, mat, m);
    }
    matcopy(mat, m);
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n, ans;
    while(cin >> n, n!=0){
        ll mat[3][3] = {
            {1, 1, 1}, 
            {1, 0, 0}, 
            {0, 1, 0}
        };

        if(n==1 || n==2 || n==3) ans = n-1;
        else{
            matexp(mat, n-3);
            ans = 2*mat[0][0] + 1*mat[0][1];
        }
        cout << ans%MOD << "\n";
    }
}
