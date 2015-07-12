#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int n, k, w;
long long int ans;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> k >> n >> w;
    ans = 0;
    for(long int i=1; i<=w; i++){
        ans += k*i;
    }
    if(ans>=n)
        ans -= n;
    else ans = 0;
    cout << ans << "\n";
}
