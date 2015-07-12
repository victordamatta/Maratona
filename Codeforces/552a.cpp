#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int x1, x2, ay1, y2, n, mat[105][105];
long int ans;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            mat[i][j] = 0;
    for(int x=0; x<n; x++){
        cin >> x1 >> ay1 >> x2 >> y2;
        for(int i = ay1; i<=y2; i++){
            for(int j = x1; j<=x2; j++){
                mat[i][j]++;
            }
        }
    }
    ans = 0;
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            ans+=mat[i][j];
    cout << ans << "\n";
}
