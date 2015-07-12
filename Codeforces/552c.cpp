//TOTALLY WRONG
#include <bits/stdc++.h>
using namespace std;
//REMEMBER TO DECLARE GLOBAL VARIABLES

long int m, tmp, w, aux;
int ok;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> w >> m;
    ok = 0;
    for(long int i=1; i<w && ok==0; i++){
        tmp = m;
        ok = 0;
        if(tmp%i==0){
            tmp/=i;
            while(tmp%w==0){
                tmp/=w;
            }
            if(tmp==1){
                ok = 1;
            }
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
