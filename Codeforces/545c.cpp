#include <iostream>
using namespace std;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int n, ans;
long int x[100005], h[100005];

void count(long int cur, long int l, long int r){
    if(cur==n-1) return;
    if(l > h[cur]) 
    {
        ans++;
        count(cur+1, x[cur+1]-x[cur], x[cur+2]-x[cur+1]);
    }
    if(r <= h[cur]) count(cur+1, x[cur+1]-x[cur], x[cur+2]-x[cur+1]);
    if(r>h[cur]){
        ans++;
        count(cur+1, x[cur+1]-x[cur]-h[cur], x[cur+2]-x[cur+1]);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(long int i = 0; i<n; i++){
        cin >> x[i] >> h[i];
    }
    ans = 2;
    count(1, x[1]-x[0], x[2]-x[1]);
    cout << ans << "\n";
}
