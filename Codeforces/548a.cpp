#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES
string in;
num k;

int ispal(string a, int size){
    int x=0, y=size-1, ok=1;
    while(x<y){
        if(a[x]!=a[y]){
            ok = 0;
            break;
        }
        x++;
        y--;
    }
    return ok;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> in >> k;
    int size = in.length(), ok=1, ps, ini;
    if(size%k!=0)
        cout << "NO\n";
    else{
        ps = size/k;
        ini = 0;
        while(ini < size && ok){
            ok = ispal(in.substr(ini, ps), ps);
            ini += ps;
        }
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
