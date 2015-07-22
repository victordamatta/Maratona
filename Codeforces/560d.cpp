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

int eqal(int a1, int b1, int size){
    if(size%2==1){
        int ok = 1;
        for(int i=0; i<size; i++){
            if(a[a1+i]!=b[b1+i]){
                ok = 0;
                break;
            }
        }
        return ok;
    }
    else{
        int ans1, ans2, aux;
        ans1 = eqal(a1, b1, size/2)*eqal(a1+size/2, b1+size/2, size/2);
        ans2 = eqal(a1+size/2, b1, size/2)*eqal(a1, b1+size/2, size/2);

        if(ans1 || ans2) return 1;
        else return 0;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> a >> b;
    int size = a.length();

    int ans = eqal(0, 0, size);
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}
