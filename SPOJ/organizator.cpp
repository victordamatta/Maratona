#include <iostream>
#include <algorithm>
#include <cstring>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int v[2000005];

int main(){
    std::ios::sync_with_stdio(false);
    long long int n, tmp, max, max2, ans;
    memset(v, 0, sizeof v);
    cin >> n;
    max2 = 0;
    for(long int i=0; i<n; i++){
        cin >> tmp;
        v[tmp]++;
        if(tmp > max2) max2 = tmp;
    }
    tmp = 1;
    max = 0;
    while(tmp <= max2){
        ans = 0;
        for(long int i=1; tmp*i<=max2; i++){
            if(v[tmp*i]){
                ans += v[tmp*i]*tmp;
            }
        }
        if(ans > max && ans>tmp) max = ans; 
        tmp++;
    }
    cout << max << "\n";
}
