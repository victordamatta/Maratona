
#include <iostream>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n;
long long int ans;

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> n, n!=0){
        ans = 0;
        for(int i=1; i<=n; i++){
            ans += (n-i+1)*(n-i+1);
        }
        cout << ans << "\n";
    }
}
