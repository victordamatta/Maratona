#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, ar[1000005];
long long int ans, tsum, sum, cont[1000005];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    sum = 0;
    for(int i=0; i<n; i++){
        cin >> ar[i];
        sum+=ar[i];
    }
    if(sum%3!=0)
        cout << "0\n";
    else{
        sum/=3;
        tsum = 0;
        for(int i=n-1; i>=0; i--){
            tsum += ar[i];
            if(tsum == sum)
                cont[i] = 1;
        }
        for(int i = n-2; i>=0; i--){
            cont[i] += cont[i+1];
        }
        ans = 0;
        tsum = 0;
        for(int i=0; i+2<n; i++){
            tsum += ar[i];
            if(tsum == sum){
                ans += cont[i+2];
            }
        }
        cout << ans << "\n";
    }
}
