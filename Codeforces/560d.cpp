#include <iostream>
#include <string>
/*
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
*/
using namespace std;
//REMEMBER TO DECLARE GLOBAL VARIABLES

string a, b;

bool eqal(int a1, int b1, int size){
    if(size%2==1){
        bool ok = true;
        for(int i=0; i<size; i++){
            if(a[a1+i]!=b[b1+i]){
                ok = false;
                break;
            }
        }
        return ok;
    }
    else{
        bool ans1, ans2, aux;
        ans1 = eqal(a1, b1, size/2) && eqal(a1+size/2, b1+size/2, size/2);
        ans2 = ans1 || eqal(a1+size/2, b1, size/2) && eqal(a1, b1+size/2, size/2);

        return ans2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> a >> b;

    bool ans = eqal(0, 0, a.size());
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}
