#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

num n, s, t, pos[100005];

int fp(num con, num cur, num target){
    int x;
    if(pos[cur]==-1)
        return -1;
    if(cur==target)
        return con;
    x = pos[cur];
    pos[cur] = -1;
    return fp(con+1, x, target);
}

int main(){
    std::ios::sync_with_stdio(false);
    num ans, con, cur;
    cin >> n >> s >> t;
    for(num i=1; i<=n; i++){
        cin >> pos[i];
    }
    ans = fp(0, s, t);
    cout << ans << "\n";
}
