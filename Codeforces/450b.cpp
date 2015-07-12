#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int x, y, n, m;
vector<long int> memo(4);

long int seq(int i){
    if(i==1 || i==2 || i==3)
        return memo[i];
    if(n%3==0)
        if((n/3)%2==1)
            return memo[3];
        else
            return -memo[3];
    else if(n%3==1)
        if((n/3)%2==1)
            return memo[1];
        else
            return -memo[1];
    else
        if((n/3)%2==1)
            return memo[2];
        else
            return -memo[2];
}

int main(){
    std::ios::sync_with_stdio(false);
    long int ans;
    m = 1000000007;
    cin >> x >> y >> n;
    memo[1] = x;
    memo[2] = y;
    memo[3] = y-x;
    ans = seq(n) % m;
    if(ans<0)
        ans += m;
    cout << ans << "\n";
}
