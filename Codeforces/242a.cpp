#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int x, x2, y, a, b, n;
int ans[5051][2];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> x >> y >> a >> b;
    x-=a;
    y-=b;
    while(a<=b && x>0){
        x--;
        a++;
    }
    if(a<=b){
        cout << "0\n";
    }
    else{
        n = 0;
        for(int i = 0; i<=x; i++){
            for(int j = 0; j<=y && b+j<a+i; j++){
                ans[n][0] = a+i;
                ans[n][1] = b+j;
                n++;
            }
        }
        cout << n << "\n";
        for(int x = 0; x<n; x++){
            cout << ans[x][0] << " " << ans[x][1] << "\n";
        }
    }
}
