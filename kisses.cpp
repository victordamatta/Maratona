#include <bits/stdc++.h>
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

void matmult(long long int mat[2][2], long long int n){
    int a, b, c, d;
    if(n==1) return;
    if(n%2==0){
        a = mat[0][0];
        b = mat[0][1];
        c = mat[1][0];
        d = mat[1][1];
        mat[0][0] = a*a + b*c;
        mat[0][1] = a*b + b*d;
        mat[1][0] = c*a + d*c;
        mat[1][1] = c*b + d*d;
        matmult(mat, n/2);
    }
    else{
        long long int mm[2][2];
        mm[0][0] = mat[0][0];
        mm[0][1] = mat[0][1];
        mm[1][0] = mat[1][0];
        mm[1][1] = mat[1][1];
        matmult(mm, n-1); 
        mat[0][0] = mat[0][0]*mm[0][0] + mat[0][1]*mm[1][0];
        mat[0][1] = mat[0][0]*mm[0][1] + mat[0][1]*mm[1][1];
        mat[1][0] = mat[1][0]*mm[0][0] + mat[1][1]*mm[1][0];
        mat[1][1] = mat[1][0]*mm[0][1] + mat[1][1]*mm[1][1];
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
            ans = 2*mat[0][0] + 2*mat[0][1];
            ans += 1ll<<(n/2);
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
            ans = 2*mat[0][0] + 2*mat[0][1];
        }
        cout << ans << "\n";
    }
}
