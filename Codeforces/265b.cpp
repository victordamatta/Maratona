#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int n, ans, oh, nh;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> oh;
    ans = oh+1;
    for(int i=1; i<n; i++){
        cin >> nh;
        ans+=2;
        if(nh<oh){
            ans+=oh-nh;
        }
        else if(nh>oh){
            ans+=nh-oh;
        }
        oh = nh;
    }
    cout << ans << "\n";
}
