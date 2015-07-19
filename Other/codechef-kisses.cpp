#include <iostream>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
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

ll fastexp(ll a, ll k){
    if(k==0) return 1;
    if(k==1) return a;
    if(k%2==0){
        return (fastexp((a*a)%MOD, k/2))%MOD;
    }
    else{
        return (a*(fastexp(a, k-1))%MOD)%MOD;
    }
}

void matmult(long long int mat[2][2], long long int n){
    if(n==1) return;
    if(n%2==0){
        ll mat2[2][2];
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                mat2[i][j] = 0;
                for(int k=0; k<2; k++){
                    mat2[i][j] += (mat[i][k]*mat[k][j]);
                    mat2[i][j] = mat2[i][j]%MOD;
                }
            }
        }

        mat[0][0] = mat2[0][0];
        mat[0][1] = mat2[0][1];
        mat[1][0] = mat2[1][0];
        mat[1][1] = mat2[1][1];

        matmult(mat, n/2);
    }
    else{
        ll mm[2][2];
        ll mat2[2][2];

        mm[0][0] = mat[0][0];
        mm[0][1] = mat[0][1];
        mm[1][0] = mat[1][0];
        mm[1][1] = mat[1][1];

        matmult(mm, n-1); 

        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                mat2[i][j] = 0;
                for(int k=0; k<2; k++){
                    mat2[i][j] += (mat[i][k]*mm[k][j]);
                    mat2[i][j] = mat2[i][j]%MOD;
                }
            }
        }

        mat[0][0] = mat2[0][0];
        mat[0][1] = mat2[0][1];
        mat[1][0] = mat2[1][0];
        mat[1][1] = mat2[1][1];

    }
}

int main(){
    std::ios::sync_with_stdio(false);
    long int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        long long int ans; 
        long long int mat[2][2];
        mat[0][0] = 1;
        mat[0][1] = 2;
        mat[1][0] = 0;
        mat[1][1] = 2;
        if(n==1){
            ans = 2;
        }
        else if(n==2){
            ans = 4;
        }
        else if(n%2==0){
            matmult(mat, n/2-1);
            /*
            cout << "MATRIZ\n";
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            */
            ans = ((2*mat[0][0])%MOD + (2*mat[0][1])%MOD)%MOD;
            ans += fastexp(2, n/2);
            ans = ans%MOD;
        }
        else{
            matmult(mat, n/2);
            /*
            cout << "MATRIZ\n";
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            */
            ans = ((2*mat[0][0])%MOD + (2*mat[0][1])%MOD)%MOD;
        }
        cout << ans << "\n";
    }
}
