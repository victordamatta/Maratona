#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f(x) for(int i=0; i<x; i++)
#define mset(x, v) memset(x, v, sizeof x)
#define MOD 1e9+7
#define MAX 10007
using namespace std;
typedef long long ll;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int triangle[101][101];
int vpd[101][101];
int n;

int pd(int row, int col){
    if(col > row) return -INT_MAX;
    if(row > n) return 0;
    if(vpd[row][col] != -1) return vpd[row][col];

    vpd[row][col] = triangle[row][col] + max(pd(row+1, col), pd(row+1, col+1));

    return vpd[row][col];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    mset(vpd, -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            cin >> triangle[i][j];
    }

    int ans = pd(0, 0);

    cout << ans << "\n";
}
